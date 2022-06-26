/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:56:08 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/26 15:57:30 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	s_quote(char *line_read)
{
	const char	quote = '\'';

	while (*line_read)
	{
		if (*line_read == quote)
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

	while (*line_read)
	{
		if (*line_read == quote)
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
		printf("Erreur de quotes\n");
		return (0);
	}
	if (!d_quote(line_read))
	{
		printf("Erreur de quotes\n");
		return (0);
	}
	return (1);
}
