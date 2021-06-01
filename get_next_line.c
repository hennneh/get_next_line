/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_join(int fd, char **buff, char **line, int readcount, int j)
{
	char	*dest;

	dest = malloc(sizeof(char) * (j + readcount + 1));
	ft_memcpy(dest, *line, j);
	ft_memcpy(&dest[j], buff[fd], readcount);
	dest[j + readcount] = '\0';
	*line = dest;
	return (j + readcount);
}

static int	ft_line_check(int fd, char **buff, char **line, int readcount)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	readcount = read(fd, buff[fd], BUFFER_SIZE);
	while (i < readcount && buff[fd][i] != '\n')
		i++;
	if (buff[fd][i] == '\n')
	{
		buff[fd][i] = '\0';
		if (!*line)
			*line = ft_strdup(buff[fd]);
		else
			j = ft_join(fd, buff, line, readcount, j);
	}
	return (0);
}

static int	ft_nl_check(int fd, char **buff, char **line)
{
	int		i;

	i = 0;
	while (buff[fd][i] != '\n')
	{
		i++;
		if (!buff[fd][i])
			return (0);
	}
	buff[fd][i] = '\0';
	*line = ft_strdup(buff[fd]);
	buff[fd] = ft_strdup(buff[fd] + i + 1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[MAX_OPEN];
	int			readcount;
	int			check;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_OPEN || !line)
		return (-1);
	if (buff[fd])
	{
		if (ft_nl_check(fd, buff, line))
			return (1);
		else
			*line = ft_strdup(buff[fd]);
	}
	readcount = 0;
	buff[fd] = ft_strdup("");
	check = ft_line_check(fd, buff, line, readcount);
	return (readcount + check);
}
