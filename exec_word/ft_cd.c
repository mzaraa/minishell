/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:44:45 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/12 13:10:20 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	change_env_dir(t_env **env, char *new_pwd, char *old_pwd)
{
	t_env	*temp;

	temp = *env;
	while (temp)
	{
		if (ft_strcmp(temp->var, "PWD") == 0)
		{
			free(temp->value);
			temp->value = ft_strdup(new_pwd);
			break ;
		}
		temp = temp->next;
	}
	temp = *env;
	while (temp)
	{
		if (ft_strcmp(temp->var, "OLD_PWD") == 0)
		{
			free(temp->value);
			temp->value = ft_strdup(old_pwd);
			break ;
		}
		temp = temp->next;
	}
}

static char	*get_env_val(t_env **env, char *old_pwd)
{
	t_env	*temp;

	temp = *env;
	while (temp)
	{
		if (ft_strcmp(temp->var, old_pwd) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	ft_cd(t_data *data, t_tree *node)
{
	char	*new_pwd;
	char	old_pwd[4096];
	char	temp_pwd[4096];

	getcwd(old_pwd, 4096);
	if (node->right && *(node->right->token) != ' '
		&& *(node->right->token) != '\0')
	{
		if (ft_strcmp(node->right->token, "-") == 0)
		{
			new_pwd = get_env_val(data->ll_env, "OLDPWD");
			printf("OLD = %s --- NEW = %s\n", old_pwd, new_pwd);
		}
		else if (node->right != NULL && *(node->right->token) != '|')
			new_pwd = node->right->token;
	}
	else
		new_pwd = get_env_val(data->ll_env, "HOME");
	chdir(new_pwd);
	change_env_dir(data->ll_env, getcwd(temp_pwd, 4096), old_pwd);
}
