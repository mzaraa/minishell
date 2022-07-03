/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:32 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/29 10:45:08 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	line_read = readline ("\033[0;32mminishell \033[0;32m» \033[0m");
	if (line_read && *line_read)
	{
		add_history (line_read);
		if (!valid_quote(line_read))
			return (line_read);
		data->cmd = line_read;
		lexer(data);
		// env_var_to_value(data);
		parser(data);
		// print_list_env(data);
		// print_list_token(data);
		print_tree((*data->ast_tree));
	}
	return (line_read);
}

int	main(int ac, char **av, char **env)
{
	t_data		data;
	t_tokens	*tokens;
	t_tree		*node;
	t_env		*env_list;

	tokens = NULL;
	node = NULL;
	env_list = NULL;
	env_list = get_env(env);
	data.ac = ac;
	data.av = av;
	data.ll_token = &tokens;
	data.cmd = NULL;
	data.ast_tree = &node;
	data.ll_env = &env_list;
	while (rl_gets(&data))
		;
	printf("Bye \n");
}
