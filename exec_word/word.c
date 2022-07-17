/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:42:24 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/16 16:19:38 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(char **tab)
{
	int	i;

	i = 0;
	if (tab[i] != NULL)
	{
		while (tab[i] != NULL)
			free(tab[i++]);
		free(tab);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	ptr = NULL;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!ptr)
		return (ptr);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i++] = s2[j++];
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	word_check(t_data *data, t_tree *node)
{
	int	flag;

	flag = is_builtin(data, node, node->token);
	if (flag == 0)
		ft_execve(data, node, node->token);
	data->is_sig = 0;
}
