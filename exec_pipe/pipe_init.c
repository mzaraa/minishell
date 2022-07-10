/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:39:42 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/10 12:40:09 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	stdin_pipe(t_data *data, int *pipefd, t_tree *node)
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
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		close(pipefd[0]);
		node->left->function(data, node->left);
		exit(0);
	}
}

static void	stdout_pipe(t_data *data, int *pipefd, t_tree *node)
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
	stdout_pipe(data, pipefd, node);
	stdin_pipe(data, pipefd, node);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
}
