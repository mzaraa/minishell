/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:35:48 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/13 17:12:20 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	swap(t_tokens **node, char *value)
{
	free((*node)->token);
	(*node)->token = strdup(value);
}

static int	replace_env(t_env **env, t_tokens *token_node)
{
	t_env		*temp_env;
	t_tokens	*node;

	temp_env = *env;
	node = token_node;
	while (temp_env)
	{
		if ((strcmp(temp_env->var, (node->token + 1))) == 0)
		{
			swap(&node, temp_env->value);
			return (1);
		}
		temp_env = temp_env->next;
	}
	return (0);
}

void	env_var_to_value(t_data *data)
{
	t_tokens	*node;
	int			flag;

	node = *(data->ll_token);
	flag = 1;
	while (node)
	{
		if (node && *(node->token) == '$' && *(node->token + 1) == '?')
			swap(&node, ft_itoa(data->exit_code));
		if (node && *(node->token) == '$')
		{
			flag = replace_env(data->ll_env, node);
			if (flag == 0)
				swap(&node, " ");
		}
		node = node->next;
	}
}
