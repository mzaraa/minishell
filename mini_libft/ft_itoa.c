/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:47:19 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/12 15:58:30 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char* ft_itoa(int nb)
// {
// 	char buf[12];
// 	char* str;
// 	int i = 12;
// 	int j = 0;
// 	int neg = 0;

// 	if (nb < 0)
// 		neg++;
// 	else
// 		nb = -nb;
// 	do {
// 		buf[--i] = '0' - nb % 10;
// 		nb /= 10;
// 	} while (nb);
// 	str = malloc(sizeof(char) * ((12 - i + neg) + 1));
// 	if (neg)
// 		str[j++] = '-';
// 	while (12-i)
// 		*(str + j++) = *(buf+i++);
// 	*(str+j) = '\0';
// 	return str;
// }

int	ft_strnb_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/*
Alloue et retourne une chaine de caractères représentant l’integer 
reçu en argument. Les nombres négatifs doivent être gérés.
*/
char	*ft_itoa(int n)
{
	char	*strnb;
	int		str_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str_len = ft_strnb_len(n);
	strnb = malloc(sizeof(char) * str_len + 1);
	if (!strnb)
		return (NULL);
	if (n < 0)
	{
		strnb[0] = '-';
		n *= -1;
	}
	strnb[str_len--] = '\0';
	while (n && (n > 0))
	{
		strnb[str_len--] = 48 + (n % 10);
		n /= 10;
	}
	return (strnb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str= ft_itoa(-2147483647);
// 	printf("%s\n", str);
// 	printf("%d", ft_strnb_len(264121));
// 	return (0);
// }
