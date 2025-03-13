#include "../minishell.h"

void ft_env(char *const envp[])
{
	int i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
