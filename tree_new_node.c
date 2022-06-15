/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:41:03 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/14 15:14:35 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Alloue et renvoie un nouvel élément. la variable content est initialisée à 
l’aide de la valeur du paramètre content. 
La variable ’next’ est initialisée à NULL.
*/
t_node	*tree_new_node(void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->right = NULL;
	node->left = NULL;
	return (node);
}
