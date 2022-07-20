/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_replace_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:59:29 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/20 17:05:28 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_var_val_in_token(t_data *data, t_tokens *node)
{
	char	*temp;
	char	*to_free;
	int		j;
	int		i;

	temp = calloc(2048, sizeof(char));
	to_free = node->token;
	j = 0;
	i = 0;
	while (node->token[i])
	{
		if (state(node, i))
		{
			++i;
			continue ;
		}
		if (node->token[i] == '$' && node->state != SIMPLE_Q
			&& check_char_for_var(node->token[i + 1]))
			j = var_to_value(data, (node->token + i), temp, j);
		else
		{
			temp[j] = node->token[i];
			++i;
			++j;
		}
	}
	free(node->token);
}

void	env_var_to_value(t_data *data)
{
	t_tokens	*node;

	node = *(data->ll_token);
	while (node)
	{
		get_var_val_in_token(data, node);
		node = node->next;
	}
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