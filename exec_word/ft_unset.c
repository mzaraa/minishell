/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:46:11 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/12 10:18:59 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	remove_if_in_env(t_data *data, t_tree *node)
{
	t_env	*temp;
	t_env	*prev;

	temp = *(data->ll_env);
	prev = temp;
	if (ft_strcmp(temp->var, node->token) == 0)
	{
		free(temp);
		prev = prev->next;
		temp = prev;
		return ;
	}
	while (temp)
	{
		if (ft_strcmp(temp->var, node->token) == 0)
		{
			prev->next = temp->next;
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	ft_unset(t_data *data, t_tree *node)
{
	t_tree	*temp;

	if (!node)
		return ;
	temp = node->right;
	remove_if_in_env(data, temp);
	if (temp->right != NULL)
		ft_unset(data, temp);
}
