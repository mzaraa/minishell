/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:56:08 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/21 19:56:32 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	Check seulement si des simples et doubles quotes sont presentes et valides.
*/

static int	s_quote(char *line_read)
{
	const char	quote = '\'';
	int			flag;

	flag = 0;
	while (*line_read)
	{
		if (*line_read == '\"' && flag == 0)
			flag = 1;
		else if (*line_read == '\"' && flag == 1)
			flag = 0;
		if (*line_read == quote && flag == 0)
		{
			line_read = strchr(++line_read, quote);
			if (!line_read)
				return (0);
		}
		line_read++;
	}
	return (1);
}

static int	d_quote(char *line_read)
{
	const char	quote = '\"';
	int			flag;

	flag = 0;
	while (*line_read)
	{
		if (*line_read == '\'' && flag == 0)
			flag = 1;
		else if (*line_read == '\'' && flag == 1)
			flag = 0;
		if (*line_read == quote && flag == 0)
		{
			line_read = strchr(++line_read, quote);
			if (!line_read)
				return (0);
		}
		line_read++;
	}
	return (1);
}

int	valid_quote(char *line_read)
{
	if (!s_quote(line_read))
	{
		ft_putstr_fd("Erreur de quotes\n", 2);
		return (0);
	}
	if (!d_quote(line_read))
	{
		ft_putstr_fd("Erreur de quotes\n", 2);
		return (0);
	}
	return (1);
}
