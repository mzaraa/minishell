/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:35:48 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/21 17:53:48 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* static void	get_var_value(t_data *data);

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
} */

/* void	env_var_to_value(t_data *data)
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
	get_var_value(data);
} */

// static void	get_var_value(t_data *data)
// {
// 	t_tokens	*temp;
// 	int			i;
// 	int			flag;

// 	i = 0;
// 	flag = 1;
// 	temp = *(data->ll_token);
// 	while (temp)
// 	{
// 		ft_trim_d_quote(temp);
// 		while (temp->token && temp->token[i])
// 		{
// 			if (temp && temp->token[i] == '$' && temp->token[i + 1] == '?')
// 				swap(&temp, ft_itoa(data->exit_code));
// 			if (temp && temp->token[i] == '$')
// 				replace_in_quote(data, data->ll_env, temp);
// 			i++;
// 		}
// 		ft_trim_s_quote(temp);
// 		i = 0;
// 		temp = temp->next;
// 	}
// }
