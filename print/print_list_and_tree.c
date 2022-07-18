/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_and_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:25:43 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/18 11:25:44 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_tree(t_tree *tree)
{
	printf("%s\n", tree->token);
	if (tree->left != NULL)
	{	
		printf("left of %s: ", tree->token);
		print_tree(tree->left);
	}	
	if (tree->right != NULL)
	{	
		printf("right of %s: ", tree->token);
		print_tree(tree->right);
	}
}

void	print_list_token(t_data *data)
{
	t_tokens	*temp;

	temp = *(data->ll_token);
	while (temp)
	{
		printf("%s \n", temp->token);
		temp = temp->next;
	}
}

void	print_list_env(t_data *data)
{
	t_env	*temp;

	temp = *(data->ll_env);
	while (temp)
	{
		printf("\033[0;34m%s \033[0m= %s\n", temp->var, temp->value);
		temp = temp->next;
	}
}

void	print_list_env_only_export(t_data *data)
{
	t_env	*temp;

	temp = *(data->ll_env);
	while (temp)
	{
		printf("declare -x %s = %s\n", temp->var, temp->value);
		temp = temp->next;
	}
}
