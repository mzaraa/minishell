/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:52:26 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/26 15:52:27 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	node_to_pipe(t_tree	**tree, t_tree	*node)
{
	if ((*tree)->type == PIPE)
	{
		if ((*tree)->right == NULL)
			(*tree)->right = node;
		else
			build_tree(&(*tree)->left, node);
	}
}

static void	swap_node(t_tree **tree, t_tree **node)
{
	t_tree	*tmp;
	t_tree	*node_tmp;

	tmp = *tree;
	node_tmp = *node;
	*tree = node_tmp;
	node_tmp->right = tmp;
}

void	build_tree(t_tree	**tree, t_tree	*node)
{
	// if(*tree)
	// 	printf("ICI : %s\n", (*tree)->token);
	if (!*tree)
		*tree = node;
	else if ((*tree)->type > node->type)
		swap_node(tree, &node);
	else if ((*tree)->type == node->type)
	{
		if (node->type == PIPE)
			swap_node(tree, &node);
		else
			build_tree((&(*tree)->right), node);
	}
	else
		node_to_pipe(tree, node);
}
