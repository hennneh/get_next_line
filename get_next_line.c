/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
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
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[MAX_OPEN];
	int			readcount;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_OPEN || !line)
		return (-1);
	buff[fd] = ft_strdup("there is something inside of buff");
	if (buff[fd])
	{
		if (ft_nl_check(fd, buff, line))
			return (0);
		else
			*line = ft_strdup(buff[fd]);
	}
	buff[fd] = ft_strdup("");
	readcount = read(fd, buff[fd], BUFFER_SIZE);
	printf("buff[fd] = %s\n", buff[fd]);
	readcount = read(fd, buff[fd], BUFFER_SIZE);
	printf("buff[fd] = %s\n", buff[fd]);
	return (1);
}
