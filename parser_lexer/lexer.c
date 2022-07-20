/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:52:45 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/20 16:57:32 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
**	Creation d'une linked list composee de chaque partie de la commande entree.
**	ft_substr() => renvoie un char* correspondant au token que l'ont veut 
ajouter a la linked list.
**	arg & earg => represente l'adresse du debut et de la fin du token.
*/
void	new_token(t_data *data, char *arg, char *earg)
{
	ft_lstadd_back(data->ll_token, ft_lstnew(
			ft_substr(data->cmd, arg - data->cmd, earg - arg + 1)));
}

/*
**	Split de la commande entree en fonction des METACHAR.
**	Les METACHAR presents entre des simples ou doubles quote sont ignorees.
**	arg & earg => represente l'adresse du debut et de la fin du token.
*/
void	lexer(t_data *data)
{
	char	*arg;
	char	*earg;

	arg = data->cmd;
	while (*arg)
	{
		while (*arg == ' ')
			arg++;
		if (!*arg)
			break ;
		earg = arg;
		while (!ft_strchr(METACHAR, *arg))
		{
			if ((*earg == '\'' || *earg == '"'))
				earg = ft_strchr(earg + 1, *earg);
			if (strchr(METACHAR, *(earg + 1)))
				break ;
			++earg;
		}
		new_token(data, arg, earg);
		arg = ++earg;
	}
}

int	state(t_tokens *node, int i)
{
	if (node->token[i] == '"' && node->state == DOUBLE_Q)
		node->state = NOTHING;
	else if (node->token[i] == '\'' && node->state == NOTHING)
		node->state = SIMPLE_Q;
	else if (node->token[i] == '"' && node->state == NOTHING)
		node->state = DOUBLE_Q;
	else if (node->token[i] == '\'' && node->state == SIMPLE_Q)
		node->state = NOTHING;
	else
		return (0);
	return (1);
}

int	var_to_value(t_data *data, char *token, char *temp, int j)
{
	char	*val;
	char	*name;
	int		i;
	int		len;

	len = 0;
	if (token[i + 1] == '?')
		val = ft_itoa(data->exit_code);
	else
	{
		while (recup_var_name(token[++i]))
			++len;
		name = ft_substr((token + i + 1), 0, len + 1);
		val = 
	}
}
