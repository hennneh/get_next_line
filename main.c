#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
        char *line;
        printf("buffer size = %d\n", BUFFER_SIZE);
        int     fd = open("file3", O_RDONLY);
        printf("fd = %d\n", fd);
        int a = get_next_line(fd, &line);
		printf("return-value of gnl = %d\n", a);
		printf("\n%s\n", line);
        return (0);
}
