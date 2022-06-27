/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:45:30 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/26 15:59:33 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len++] != '\0')
		;
	str = malloc(sizeof(*s1) * len);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	strlen;
	char	*str;

	j = 0;
	strlen = 0;
	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + strlen] && strlen < len)
		strlen++;
	str = malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	while (j < strlen)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}
