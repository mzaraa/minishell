/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:39:42 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/16 16:09:15 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	stdin_pipe(t_data *data, int *pipefd, t_tree *node)
{
	int	childpid;

	childpid = fork();
	if (childpid == -1)
	{
		perror("fork : ");
		exit(1);
	}
	data->pid = childpid;
	if (childpid == 0)
	{
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		close(pipefd[0]);
		node->left->function(data, node->left);
		exit(0);
	}
	return (childpid);
}

static int	stdout_pipe(t_data *data, int *pipefd, t_tree *node)
{
	int	childpid;

	childpid = fork();
	if (childpid == -1)
	{
		perror("fork : ");
		exit(1);
	}
	if (childpid == 0)
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		node->right->function(data, node->right);
		exit(0);
	}
	return (childpid);
}

void	pipe_init(t_data *data, t_tree *node)
{
	int	pipefd[2];
	int	pids[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe : ");
		exit(1);
	}
	pids[0] = stdout_pipe(data, pipefd, node);
	pids[1] = stdin_pipe(data, pipefd, node);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pids[0], &data->status, 0);
	waitpid(pids[1], &data->status, 0);
	if (WTERMSIG(data->status) == SIGQUIT)
	{
		ft_putstr_fd("Quit :3\n", 2);
		data->status = 45;
	}
	else
		data->status = WEXITSTATUS(data->status);
}
