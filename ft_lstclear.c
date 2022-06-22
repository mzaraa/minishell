/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:02:42 by mzaraa            #+#    #+#             */
/*   Updated: 2021/11/04 16:10:54 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_tokens **lst)
{
	t_tokens *temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp);
	}
}
