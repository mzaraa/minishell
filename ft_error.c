#include "minishell.h"

void	ft_error_path(char *cmd)
{
	printf("minishell: %s: command not found\n", cmd);
	exit (127);
}