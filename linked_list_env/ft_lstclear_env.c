/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:35:21 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/10 12:35:22 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	ft_lstclear_env(t_env **lst)
{
	t_env	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone_env(temp);
	}
}
