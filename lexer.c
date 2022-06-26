/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:52:45 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/26 15:58:01 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_token(t_data *data, char *arg, char *earg)
{
	ft_lstadd_back(data->ll_token,
		ft_lstnew(ft_substr(data->cmd, arg - data->cmd, earg - arg + 1)));
}

void	lexer(t_data *data)
{
	char	*arg;
	char	*earg;

	arg = data->cmd;
	while (*arg)
	{
		if (*arg == ' ')
			arg++;
		earg = arg;
		while (!ft_strchr(METACHAR, *arg))
		{
			if (*earg == '\'' || *earg == '\"')
				earg = ft_strchr(earg + 1, *earg);
			if (strchr(METACHAR, *(earg + 1)))
				break ;
			++earg;
		}
		new_token(data, arg, earg);
		arg = ++earg;
	}
}
