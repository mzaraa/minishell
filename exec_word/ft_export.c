/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:09:55 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/10 15:54:39 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_env(t_data *data, char *var, char *value)
{
	t_env	*temp;

	temp = *data->ll_env;
	while (temp)
	{
		if (ft_strcmp(temp->var, var) == 0)
		{
			free(temp->value);
			temp->value = NULL;
			temp->value = ft_strdup(value);
			return ;
		}
		temp = temp->next;
	}
	ft_lstadd_back_env(data->ll_env, ft_lstnew_env(var, value));
}

static int	check_export(char *var)
{
	while (*var)
	{
		if (!ft_isalnum(*var))
			return (0);
		var++;
	}
	return (1);
}

void	ft_export(t_data *data, t_tree *node)
{
	t_tree	*temp;
	char	*equal;

	temp = node;
	equal = ft_strchr(temp->right->token, '=');
	if (!equal || *equal != '=')
		return ;
	*equal++ = '\0';
	if (check_export(temp->token) && *temp->token != '=')
		export_env(data, temp->token, equal);
	else
		printf("error\n");
}
