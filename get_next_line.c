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
	buff[fd] = ft_strdup("");
	readcount = read(fd, buff[fd], BUFFER_SIZE);
	if (readcount == 0)
		return (0);
	check = ft_line_check(fd, buff, line, readcount);
	return (1);
}
