/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:09:55 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/21 20:07:29 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_export_only(t_data *data, t_tree *node)
{
	if (!node->right)
	{
		print_list_env_only_export(data);
		return (1);
	}
	return (0);
}

void	export_env(t_data *data, char *var, char *value)
{
	t_env	*temp;

	temp = *data->ll_env;
	while (temp)
	{
		if (ft_strcmp(temp->var, var) == 0)
		{
			free(temp->value);
			temp->value = ft_strdup(value);
			return ;
		}
		temp = temp->next;
	}
	ft_lstadd_back_env(data->ll_env, ft_lstnew_env(
			ft_strdup(var), ft_strdup(value)));
}

static int	check_export(char *var)
{
	if (!ft_isalpha(*var) && *var != '_')
		return (0);
	while (*var)
	{
		if (!ft_isalnum(*var) && *var != '_')
			return (0);
		var++;
	}
	return (1);
}

void	ft_export(t_data *data, t_tree *node)
{
	t_tree	*temp;
	char	*equal;

	if (!node)
		return ;
	if (check_export_only(data, node))
		return ;
	temp = node;
	equal = ft_strchr(temp->right->token, '=');
	if (!equal || *equal != '=')
		return ;
	*equal++ = '\0';
	if (check_export(temp->right->token) && *temp->right->token != '=')
		export_env(data, temp->right->token, equal);
	else
	{
		printf("\033[91mExport Error\033[0m\n");
		data->exit_code = 2;
		return ;
	}
	temp = temp->right;
	if (temp->right != NULL)
		ft_export(data, node->right);
	change_env(data, data->ll_env);
}
