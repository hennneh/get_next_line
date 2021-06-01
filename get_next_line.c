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

static int	ft_nl_check(int fd, char **buff, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (buff[fd][i] != '\n')
	{
		i++;
		if (!buff[fd][i])
			return (0);
	}
	
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[MAX_OPEN];
	int			readcount;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_OPEN || !line)
		return (-1);
	if (buff[fd])
		(if ft_nl_check(fd, buff, line))
			return (1);
}
