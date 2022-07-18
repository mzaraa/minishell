/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:08:54 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/18 21:21:53 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_trim_d_quote(t_tokens *node)
{
	char	*temp;
	char	*res;
	int		i;

	i = 0;
	temp = node->token;
	res = malloc(sizeof(char) * strlen(temp) + 1);
	while (*temp)
	{
		if (*temp == '"')
		{
			res[i] = '\0';
			ft_substrcat(res, temp + 1,
				ft_strchr(temp + 1, '"') - (temp + 1));
			temp = ft_strchr(temp + 1, '"') + 1;
			i = ft_strlen(res);
			continue ;
		}
		res[i++] = *temp;
		temp++;
	}
	res[i] = '\0';
	free(node->token);
	node->token = res;
}

char	*ft_before(char *str)
{
	char	*bef;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	bef = malloc(sizeof(char) * i + 1);
	j = 0;
	while (j < i)
	{
		bef[j] = str[j];
		j++;
	}
	bef[j] = '\0';
	return (bef);
}

char	*ft_after(char *str)
{
	char	*after;
	int		i;

	i = 0;
	after = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		after[i] = str[i];
		i++;
	}
	after[i] = '\0';
	return (after);
}

static char	*replace_env_quote(t_env **env, char *token)
{
	t_env	*temp_env;
	char	*temp;

	temp_env = *env;
	while (temp_env)
	{
		if ((strcmp(temp_env->var, token + 1)) == 0)
		{
			temp = ft_strdup(temp_env->value);
			return (temp);
		}
		temp_env = temp_env->next;
	}
	return (ft_strdup(""));
}

void	replace_in_quote(t_data *data, t_env **env, t_tokens *node)
{
	char	*before;
	char	*after;
	char	*temp;
	char	*temp2;

	(void)data;
	if (*node->token != '\'')
	{
		temp = ft_strchr(node->token, '$');
		before = ft_before(node->token);
		after = ft_strdup(temp);
		temp2 = replace_env_quote(env, after);
		printf("AFTER%s BEFORE%s\n", after, before);
		if (node->token)
		{
			free(node->token);
			node->token = ft_strjoin(before, temp2);
		}
		if (after)
			free(after);
		if (before)
			free(before);
	}
}
