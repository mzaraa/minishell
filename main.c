/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:32 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/26 15:53:33 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ast(t_tree *tree)
{
	printf("%s\n", tree->token);
	if (tree->left != NULL)
	{	
		printf("left of %s: ", tree->token);
		print_ast(tree->left);
	}	
	if (tree->right != NULL)
	{	
		printf("right of %s: ", tree->token);
		print_ast(tree->right);
	}
}

/* static void	print_list(t_data *data)
{
	t_tokens	*temp;

	temp = *(data->ll_token);
	while (temp)
	{
		printf("%s \n", temp->token);
		temp = temp->next;
	}
} */

static char	*rl_gets(t_data *data)
{
	static char	*line_read = (char *) NULL;

	if (line_read)
	{
		free (line_read);
		ft_lstclear(data->ll_token);
		free_tree(data->ast_tree);
		line_read = (char *) NULL;
		data->cmd = NULL;
	}
	line_read = readline ("minishell » ");
	if (line_read && *line_read)
	{
		add_history (line_read);
		if (!valid_quote(line_read))
			return (line_read);
		data->cmd = line_read;
		lexer(data);
		parser(data);
		print_ast((*data->ast_tree));
		// print_list(data);
	}
	return (line_read);
}

int	main(int ac, char **av, char **env)
{
	t_data		data;
	t_tokens	*tokens;
	t_tree		*node;

	tokens = NULL;
	node = NULL;
	data.ac = ac;
	data.av = av;
	data.env = env;
	data.ll_token = &tokens;
	data.cmd = NULL;
	data.ast_tree = &node;
	while (rl_gets(&data))
		;
	printf("Bye \n");
}
