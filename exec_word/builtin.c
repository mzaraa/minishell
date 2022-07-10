/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:39:51 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/10 14:57:56 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 && !str2)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
/* test si ca marche echo*/
static void	ft_echo(t_data *data, t_tree *node)
{
	(void)data;
	printf("%s \n", node->right->token);
}

void	is_builtin(t_data *data, t_tree *node, char	*cmd)
{
	char *coucou[] = {
		cmd,
		NULL,
	};

	if (ft_strcmp("echo", cmd) == 0)
		ft_echo(data, node);
	// else if (ft_strcmp("cd", cmd) == 0)
	// 	ft_cd(data, node);
	// else if (ft_strcmp("pwd", cmd) == 0)
	// 	ft_pwd(data, node);
	else if (ft_strcmp("export", cmd) == 0)
		ft_export(data, node);
	// else if (ft_strcmp("unset", cmd) == 0)
	// 	ft_unset(data, node);
	else if (ft_strcmp("env", cmd) == 0)
		ft_env(data, node);
	// else if (ft_strcmp("exit", cmd) == 0)
	// 	ft_exit(data, node);
	else
		execve(coucou[0], coucou, data->env);
}
