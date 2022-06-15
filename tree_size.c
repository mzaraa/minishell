/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:41:14 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/14 15:14:10 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tree_size(t_node *node)
{
	if (!node)
		return (0);
	return (tree_size(node->left) + tree_size(node->right) + 1);
}
