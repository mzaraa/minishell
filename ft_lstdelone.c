/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:55:20 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/14 15:04:49 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Libère la mémoire de l’élément passé en argument
en utilisant la fonction del puis avec free. La
mémoire de next ne doit pas être free.
*/
void	ft_lstdelone(t_node *lst, void (*del)(void*))
{
	del(lst->content);
	free (lst);
}
