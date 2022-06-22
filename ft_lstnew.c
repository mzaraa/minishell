/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:41:03 by mzaraa            #+#    #+#             */
/*   Updated: 2022/01/20 19:27:12 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Alloue et renvoie un nouvel élément. la variable content est initialisée à 
l’aide de la valeur du paramètre content. 
La variable ’next’ est initialisée à NULL.
*/
t_tokens	*ft_lstnew(char *content)
{
	t_tokens	*ptr_fresh;

	ptr_fresh = malloc(sizeof(t_tokens));
	if (!ptr_fresh)
		return (NULL);
	ptr_fresh->token = content;
	ptr_fresh->next = NULL;
	return (ptr_fresh);
}
