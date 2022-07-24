/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:28:06 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/23 20:01:32 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	check_line(char *str)
{
	while (*str)
	{
		if (*str != ' ' )
			return (1);
		str++;
	}
	return (0);
}

int	get_status(t_data *data, int status)
{
	int	res;

	if (WIFSIGNALED(status))
	{
		res = 128 + WTERMSIG(status);
		if (data->exit_code == 131)
			printf("Quit: 3\n");
	}
	else
		res = WEXITSTATUS(status);
	return (res);
}

void	ft_error_path(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" command not found\n", 2);
	exit (127);
}
