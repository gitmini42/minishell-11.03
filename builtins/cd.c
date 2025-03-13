#include "../minishell.h"

int gotohome(char **path)
{
	*path = getenv("HOME");
	if (*path == NULL)
	{
		perror("cd: HOME not set\n");
		return (1);
	}
	return (0);
}
int gotooldpwd(char **path, char **oldpwd)
{
	if (!oldpwd)
	{
		perror("cd: OLDPWD not set\n");
		return (1);
	}
	*path = *oldpwd;
	printf("%s\n", *path);
	return (0);
}

int ft_cd(char **args, int *i)
{
	char *path;
	char cwd[1024];
	char *oldpwd;

	oldpwd = getenv("OLDPWD");
	if (args[1] == NULL || strcmp(args[1], "~") == 0)
		gotohome(&path);
	else if (strcmp(args[1], "-") == 0)
		gotooldpwd(&path, &oldpwd);
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		perror("cd");
		return 1;
	}
	if (getcwd(cwd, sizeof(cwd)))
	{	//setenv funcao proibida, tenho que corrigir
		// nao fuinciona igual o shell quando tem |
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	(*i)++;
	return 0;
}
