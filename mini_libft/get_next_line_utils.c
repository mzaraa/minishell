/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:23:28 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/05 18:06:56 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *save, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * ((ft_strlen(save) + ft_strlen(buffer)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (save[j])
		str[i++] = save[j++];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(save);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			return ((char *)&s[ft_strlen(s)]);
		i++;
	}
	return (NULL);
}
