/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:46:22 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/18 20:49:09 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_substrcat(char *dst, char *src, size_t n_byte)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (!dst && !src)
		return ;
	while (src[j] != '\0' && j < n_byte)
		dst[i++] = src[j++];
	dst[i] = '\0';
}
