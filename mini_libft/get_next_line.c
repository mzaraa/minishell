/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:23:31 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/06 20:15:58 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_rest_save(char	*save)
{
	char	*save_rest;
	size_t	rest;
	size_t	i;
	size_t	j;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free (save);
		return (NULL);
	}
	rest = ft_strlen(save);
	save_rest = malloc(sizeof(char) * (rest - i + 1));
	if (!save_rest)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		save_rest[j++] = save[i++];
	save_rest[j] = '\0';
	free(save);
	return (save_rest);
}

char	*ft_final_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i++] != '\n')
		;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*check_free_save(char *s)
{
	if (s[0] == '\0')
		free(s);
	if (!s)
		free(s);
	return (0);
}

char	*ft_get_next_line_part_two(int fd, char *save, char *buffer)
{
	int	read_l;

	read_l = 1;
	while (!ft_strchr(save, '\n') && read_l != 0)
	{
		read_l = read(fd, buffer, BUFFER_SIZE);
		if (read_l == -1)
			return (NULL);
		buffer[read_l] = '\0';
		save = ft_strjoin(save, buffer);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	save = ft_get_next_line_part_two(fd, save, buffer);
	if (!save)
		return (NULL);
	line = ft_final_line(save);
	save = ft_rest_save(save);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
