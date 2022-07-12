/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:42:24 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/12 16:09:52 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	word_check(t_data *data, t_tree *node)
{
	int	flag;

	flag = 0;
	flag = is_builtin(data, node, node->token);
	if (flag == 0)
		ft_execve(data, node, node->token);
}
