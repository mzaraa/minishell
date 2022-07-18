/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:46:11 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/18 20:22:47 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	change_env(t_data *data, t_env **env)
{
	int			i;
	t_env		*temp;
	char		**arr_env;
	static int	flag = 0;

	i = 0;
	temp = *env;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	arr_env = malloc(sizeof(char **) * (i + 1));
	i = 0;
	temp = *env;
	while (temp)
	{
		arr_env[i] = join_three(temp->var, "=", temp->value);
		temp = temp->next;
		i++;
	}
	arr_env[i] = NULL;
	if (flag)
		free_env(data->env);
	flag = 1;
	data->env = arr_env;
}

static void	remove_if_in_env(t_data *data, t_tree *node)
{
	t_env	*temp;
	t_env	**prev;

	temp = *(data->ll_env);
	prev = &temp;
	while (temp)
	{
		if (ft_strcmp(temp->var, node->token) == 0)
		{
			*prev = temp->next;
			free (temp->var);
			free (temp->value);
			free (temp);
			return ;
		}
		prev = &temp->next;
		temp = temp->next;
	}
}

void	ft_unset(t_data *data, t_tree *node)
{
	t_tree	*temp;

	if (!node)
		return ;
	temp = node->right;
	remove_if_in_env(data, temp);
	if (temp->right != NULL)
		ft_unset(data, temp);
	change_env(data, data->ll_env);
}
