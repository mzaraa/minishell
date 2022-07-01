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

void	parser(t_data *data)
{
	t_tokens	*temp;

	temp = *(data->ll_token);
	while (temp != NULL)
	{
		build_tree(data->ast_tree, ft_tree_new_node(temp->token));
		temp = temp->next;
	}
}
