/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:35:14 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/10 12:35:15 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	if (!*alst)
		*alst = new;
	else
		ft_lstlast_env(*alst)->next = new;
}
