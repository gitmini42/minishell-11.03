#include "../minishell.h"


static int	is_numeric(const char *str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	free_args(char **args)
{
	int i = 0;

	if (!args)
		return;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}


void	ft_exit(char **args)
{
	int	exit_code;

	printf("Exiting minishell...\n");
	if (args[1])
	{
		if (!is_numeric(args[1]))
		{
			write(2, "bash: exit: numeric argument required\n", 39);
			exit(255);
		}
		else if (args[2])
		{

			write(2, "bash: exit: too many arguments\n", 32);
			exit(2);
		}
		if (ft_atoi (args[1]) > 255)
			exit_code = ft_atoi(args[1]) % 255;
		else
			exit_code = ft_atoi(args[1]);
	}
	else
		exit_code = 0;
	free_args(args);
	exit(exit_code);
}
