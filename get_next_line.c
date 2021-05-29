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
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_next_line(int fd, char **line)
{
	static char	buff[MAX_FILES][BUFFER_SIZE];
	ssize_t		i;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_FILES)
		return (-1);
	i = read(fd, buff[fd], BUFFER_SIZE);
//checking if read worked and everything is stored in the 2d-array
	printf("%s\n", buff[fd]);
	return (0);
}

int     main(void)
{
        char **line;
        printf("buffer size = %d\n", BUFFER_SIZE);
        int     fd = open("file3", O_RDONLY);
        printf("fd = %d\n", fd);
        int a = get_next_line(fd, line);
        return (0);
}
