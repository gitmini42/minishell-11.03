#include "../minishell.h"

extern char **environ;

int find_env_index(const char *name)
{
    int i = 0;
    int len = strlen(name);

    while (environ[i])
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return i;
        i++;
    }
    return -1;
}

char *create_new_entry(const char *name, const char *value)
{
    char *new_entry = malloc(strlen(name) + strlen(value) + 2);
    if (!new_entry)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    ft_strcpy(new_entry, name);
    ft_strcat(new_entry, "=");
    ft_strlcat(new_entry, value, ft_strlen(value));
    return (new_entry);
}

void update_existing_env(int index, char *new_entry)
{
    free(environ[index]);
    environ[index] = new_entry;
}

void add_new_env(char *new_entry)
{
    int env_count = 0;
    while (environ[env_count])
        env_count++;

    char **new_environ = malloc((env_count + 2) * sizeof(char *));
    if (!new_environ)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (i < env_count)
    {
        new_environ[i] = environ[i];
        i++;
    }

    new_environ[env_count] = new_entry;
    new_environ[env_count + 1] = NULL;
    environ = new_environ;
}

void add_or_update_env(const char *name, const char *value)
{
    int index = find_env_index(name);
    char *new_entry = create_new_entry(name, value);

    if (index != -1)
        update_existing_env(index, new_entry);
    else
        add_new_env(new_entry);
}

static void	define_var(char **args, char *equal_sign, int i)
{
	char *name;
	char *value;

	name = ft_strndup(args[i], equal_sign - args[i]);
	value = ft_strdup(equal_sign + 1);
	if (!name || !value)
	{
		perror("malloc");
		exit(1);
	}
	add_or_update_env(name, value);
	free(name);
	free(value);
}
void ft_export(char **args,  char *const envp[])
{
	char *equal_sign;
    int i = 1;

    if (!args[1])
		ft_env(envp);
    while (args[i])
    {
        equal_sign = ft_strchr(args[i], '=');
        if (equal_sign)
			define_var(args, equal_sign, i);
        else
        {
            // ✅ Mostra o valor atual da variável, se existir
            char *value = getenv(args[i]);
            if (value)
                printf("declare -x %s=\"%s\"\n", args[i], value);
            else
                printf("declare -x %s\n", args[i]);
        }
        i++;
    }
}
