#include "../minishell.h"

	int fork_builtin(char *command, char **args)
	{
		if (ft_strcmp(command, "echo") == 0)
			return (ft_echo(args), 1);
		if (ft_strcmp(command, "pwd") == 0)
			return (ft_pwd(), 1);
		if (ft_strcmp(command, "cd") == 0)
			return (1);
		if (ft_strcmp(command, "env") == 0)
			return (1);
		if (ft_strcmp(command, "exit") == 0)
			return (1);
		if (ft_strcmp(command, "export") == 0)
			return (1);
		return 0;
	}
void	parent_builtin(char *command, char **args, int *i, char *const envp[])
{
	if(ft_strcmp(command, "cd") == 0)
		ft_cd(args, i);
    if (ft_strcmp(command, "env") == 0)
        ft_env(envp);
    if (ft_strcmp(command, "exit") == 0)
        ft_exit(args);
    if (strcmp(command, "export") == 0)
        ft_export(args, envp);
}
