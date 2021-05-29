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

static int	check_buff(char **buff, char **line)
{
	char	*end;
	char	*tmp;

	if (!buff[fd])
		buff[fd] = ft_strdup("");
	if (!buff[fd])
		return (-1);
	end = ft_strchr(buff[fd], '\n');
	if (end)
	{
		*end = 0;
		tmp = *buff;
		*line = ft_strdup(*buff);
		*buff = ft_strdup(end + 1);
		if (!(*buff)
			return (-1);
		free(tmp);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[MAX_FILES][BUFFER_SIZE];
	int			i;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_FILES || !line)
		return (-1);
	i = check_buff(&buff[fd], line);
}
