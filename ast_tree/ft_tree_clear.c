/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:57:11 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/13 16:53:58 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tree(t_tree **tree)
{
	t_tree	*tmp;

	if (!*tree)
		return ;
	tmp = *tree;
	if (tmp)
	{
		free_tree(&tmp->right);
		free_tree(&tmp->left);
	}
	free (tmp->token);
	free (tmp);
	*tree = NULL;
}
