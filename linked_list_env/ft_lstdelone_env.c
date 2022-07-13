/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:35:29 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/13 16:52:45 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	ft_lstdelone_env(t_env *lst)
{
	if (lst)
	{
		free (lst->value);
		free (lst->var);
		free (lst);
	}
}
