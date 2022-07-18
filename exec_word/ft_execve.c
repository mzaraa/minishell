/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:10:13 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/18 21:41:14 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

char	**arr_arg(t_tree *node)
{
	int		i;
	char	**arr;
	t_tree	*temp;

	i = 0;
	temp = node;
	arr = malloc(sizeof(char **) * 50);
	while (temp && temp->type == WORD)
	{
		arr[i] = temp->token;
		i++;
		temp = temp->right;
	}
	arr[i] = NULL;
	return (arr);
}

char	*find_path(t_data *data, int i, char *cmd)
{
	char	*tmp;
	char	**path_bis;
	char	*path;

	path_bis = NULL;
	path = NULL;
	while (!ft_strnstr(data->env[i], "PATH", 4))
		i++;
	path_bis = ft_split(data->env[i] + 5, ":");
	i = 0;
	while (path_bis[i++])
	{
		tmp = ft_strjoin(path_bis[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
		{
			free_all(path_bis);
			return (path);
		}
		free(path);
	}
	free_all(path_bis);
	return (NULL);
}

static void	is_forked(t_data *data, t_tree *node, char *cmd)
{
	char	*path;
	int		flag;

	flag = 0;
	path = cmd;
	while (*path)
	{
		if (*path == '/')
			flag = 1;
		path++;
	}
	if (flag)
	{
		if (execve(cmd, arr_arg(node), data->env) == -1)
			ft_error_path(cmd);
	}
	else if (find_path(data, 0, cmd) == NULL)
		ft_error_path(cmd);
	else
		execve(find_path(data, 0, cmd), arr_arg(node), data->env);
	ft_putstr_fd("ERROR\n", 2);
}

void	ft_execve(t_data *data, t_tree *node, char *cmd)
{
	int	flag;
	int	pid;

	data->exit_code = 0;
	flag = 0;
	if ((*(data->ast_tree))->type == PIPE)
		flag = 1;
	if (flag == 1)
		is_forked(data, node, cmd);
	else
	{
		pid = fork();
		data->pid = pid;
		if (pid == 0)
		{
			is_forked(data, node, cmd);
			exit(127);
		}
		waitpid(pid, &data->status, 0);
		data->exit_code = get_status(data, data->status);
	}
}
