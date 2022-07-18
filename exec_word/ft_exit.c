/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:25:13 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/18 11:27:07 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = (str[i++] - '0') + (res * 10);
	return (res * neg);
}

int	is_num(char *token)
{
	if (*token == '-')
		++token;
	while (*token)
	{
		if (!ft_isdigit(*token))
			return (1);
		++token;
	}
	return (0);
}

void	ft_exit(t_data *data, t_tree *node)
{
	t_tree	*temp;

	(void)data;
	temp = node;
	while (temp)
	{
		temp = temp->right;
		if (!temp)
			break ;
		if (temp->right)
		{
			ft_putstr_fd("exit : too many args\n", 2);
			return ;
		}
		if (is_num(temp->token))
		{
			ft_putstr_fd("exit : non numeric arg\n", 2);
			return ;
		}
		printf("exit\n");
		exit(ft_atoi(temp->token));
	}
	printf("exit\n");
	exit(0);
}
