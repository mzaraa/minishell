/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:46:13 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/18 20:10:35 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_inset(char c, const char *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		front;
	int		rear;

	front = 0;
	rear = 0;
	if (!s1)
		return (0);
	while (ft_inset(s1[front], set))
		front++;
	while (s1[rear])
		rear++;
	while (ft_inset(s1[rear - 1], set) && rear > front)
		rear--;
	str = (char *)malloc(sizeof (char) * ((rear - front) + 1));
	if (!str)
		return (str);
	str[rear - front] = '\0';
	while (rear-- > front)
		str[rear - front] = s1[rear];
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%s\n", ft_strtrim("abqbc", "abc"));
// 	printf("%s\n", ft_strtrim("xavocadoyz", "xyz"));
// 	return 0;
// }