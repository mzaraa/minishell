/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:35:51 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/12 09:34:35 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_var(char *env)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	while (env[i] && env[i] != '=')
		i++;
	var = malloc(sizeof(char) * (i + 1));
	if (!var)
		return (NULL);
	while (j < i)
	{
		var[j] = env[j];
		j++;
	}
	var[j] = '\0';
	return (var);
}

static char	*get_value(char *env)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	while (*env && *env != '=')
		env++;
	env++;
	while (env[i])
		i++;
	value = malloc(sizeof(char) * (i + 1));
	if (!value)
		return (NULL);
	while (j < i)
	{
		value[j] = env[j];
		j++;
	}
	value[j] = '\0';
	return (value);
}

t_env	*get_env(char **env)
{
	t_env	*temp;
	int		i;

	temp = NULL;
	i = 0;
	while (env[i])
	{
		ft_lstadd_back_env(
			&temp, ft_lstnew_env(
				get_var(env[i]), get_value(env[i])));
		i++;
	}
	return (temp);
}
