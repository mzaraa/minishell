/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:52:32 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/08 14:44:47 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// TO DO : function for node type

t_tree	*ft_tree_new_node(char *token)
{
	t_tree	*new_node;

	new_node = malloc(sizeof(t_tree));
	new_node->token = strdup(token);
	new_node->left = NULL;
	new_node->right = NULL;
	if (*token == '|' && !(*(token + 1)))
	{
		new_node->type = PIPE;
		new_node->function = pipe_init;
	}
	else
	{
		new_node->type = WORD;
		new_node->function = word_check;
	}
	return (new_node);
}
