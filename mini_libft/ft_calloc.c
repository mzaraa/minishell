/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:45:00 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/21 15:22:12 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// comme memset mais avec des zeros
static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// alloue de la memoire et rempli cette memoire par des zeros
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr_ma;

	ptr_ma = malloc(count * size);
	if (!ptr_ma)
		return (NULL);
	ft_bzero(ptr_ma, count * size);
	return (ptr_ma);
}
