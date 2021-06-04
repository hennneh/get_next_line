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

static char	*ft_line(char *buff, char **line, int readcount)
{
	unsigned int	i;
	char			*str;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(buff))
	{
		*line = ft_substr(buff, 0, i);
		str = ft_substr(buff, i + 1, ft_strlen(buff));
		free(buff);
		buff = ft_strdup(str);
		free (str);
	}
	else if (readcount == 0)
	{
		*line = buff;
		buff = NULL;
	}
	return (buff);
}

static char	*ft_join(char *temp, char *buff)
{
	char	*str;

	if (buff)
	{
		str = ft_strjoin(buff, temp);
		free(buff);
		buff = ft_strdup(str);
		free(str);
	}
	else
		buff = ft_strdup(temp);
	return (buff);
}

int	ft_check(int fd, char **line, char **buff, char *temp)
{
	int			readcount;

	readcount = read(fd, temp, BUFFER_SIZE);
	while (readcount)
	{
		if (readcount == -1)
			return (-1);
		temp[readcount] = '\0';
		buff[fd] = ft_join(temp, buff[fd]);
		if (ft_strchr(temp, '\n'))
			break ;
		readcount = read(fd, temp, BUFFER_SIZE);
	}
	if (readcount < 1 && !buff[fd])
	{
		*line = ft_strdup("");
		return (readcount);
	}
	buff[fd] = ft_line(buff[fd], line, readcount);
	if (readcount <= 0 && !buff[fd])
		return (readcount);
	return (-2);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[MAX_FD];
	char		temp[BUFFER_SIZE + 1];
	int			check;

	if (!line || fd < 0 || fd > MAX_FD || BUFFER_SIZE < 0)
		return (-1);
	check = ft_check(fd, line, buff, temp);
	if (check != -2)
		return (check);
	return (1);
}
