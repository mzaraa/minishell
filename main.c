/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:32 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/13 16:54:56 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int *g_sig = NULL;

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		*g_sig = 130;
	}
}

/* 
**	Recup la commande avec readline()
**	Check si la commande n'est pas '\0' et si les quotes sont valides
**	Si commande valide => split la commande en token puis creation de l'arbre
**	Si commande invalide ou valide => return la commande
**	Au rappel de la fonction, free tout les elements malloc.
*/
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
	//line_read = ft_strdup("pwd");
	line_read = readline ("minishell » ");
	if (line_read && *line_read)
	{
		add_history (line_read);
		if (!valid_quote(line_read))
			return (line_read);
		data->cmd = line_read;
		lexer(data);
		env_var_to_value(data);
		parser(data);
		// print_list_env(data);
		// print_list_token(data);
		// print_tree((*data->ast_tree));
	}
	return (line_read);
}

/* 
**	Initialisation des variables des structures du programme
**	Lancement de la boucle
*/
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
	data.env = env;
	data.ac = ac;
	data.av = av;
	data.ll_token = &tokens;
	data.cmd = NULL;
	data.ast_tree = &node;
	data.ll_env = &env_list;
	data.status = 0;
	g_sig = &data.status;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sig);
	while (rl_gets(&data))
		;
	printf("exit\n");
}
