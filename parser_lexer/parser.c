/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:56:37 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/21 20:08:17 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
**	Parcours les nodes de l'arbre pour verifier qu'il soit valide 
(bien construit, donc executable).
*/
static int	tree_invalid(t_tree **tree)
{
	t_tree	*node;

	node = *tree;
	if (!node)
		return (0);
	if (node->type == PIPE)
		if (!node->left)
			return (1);
	if (tree_invalid(&node->right))
		return (1);
	if (tree_invalid(&node->left))
		return (1);
	return (0);
}

/*
**	 On commence en haut de l'arbre binaire et on execute les fonctions 
correspondantes a chaque node.
*/
static void	tree_top_down_exec(t_data *data)
{
	t_tree	*root;

	root = *(data->ast_tree);
	root->function(data, root);
}

/*
**	Chaque token de la linked list est envoyee a la fonction ft_tree_new_node().
**	Le node construit, on l'ajoute a l'arbre.
**	Check si l'arbre est valid.
**	Execution de l'arbre.
**	temp => linked list de token & useless => juste pour que les flags de 
compilation la ferme sur linux.
*/
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
		printf("\033[91merror\033[0m\n");
		useless++;
		return ;
	}
	tree_top_down_exec(data);
}
