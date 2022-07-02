/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:56:37 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/01 13:56:43 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tree_invalid(t_tree **tree)
{
	t_tree	*node;

	node = *tree;

	if (!node)
		return (1);
	if (node->type == PIPE)
		if (!node->left)
			return (1);
	if (tree_invalid(&node->right))
		return (1);
	if (tree_invalid(&node->left))
		return (1);
	return 0;
}

static void	tree_top_down_exec(t_data *data)
{
	t_tree	*root;
	int	pipefd[2];

	pipefd[0] = dup(0);
	pipefd[1] = dup(1);
	root = *(data->ast_tree);
	root->function(data);
	dup2(pipefd[0], 0);
	dup2(pipefd[1], 1);
}

void	parser(t_data *data)
{
	t_tokens	*temp;
	int			useless;

	temp = *(data->ll_token);
	useless = 0;
	while (temp != NULL)
	{
		build_tree(data->ast_tree, ft_tree_new_node(temp->token));
		temp = temp->next;
	}
	if (tree_invalid(data->ast_tree))
	{
		useless = write(2, "error\n", 6);
		useless++;
		return ;
	}
	tree_top_down_exec(data);
}
