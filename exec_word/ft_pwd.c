/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:25:40 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/12 10:34:48 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_data *data, t_tree *node)
{
	char	buffer[4096];
	char	*pwd;

	pwd = getcwd(buffer, 4096);
	if (!pwd)
		return ;
	printf("%s\n", pwd);
}
