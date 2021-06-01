#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char     *ft_strdup(const char *s)
{
        char    *dest;
        size_t  i;
        size_t  len;

        len = 0;
        while (s[len] != '\0')
                len++;
        dest = (char *)malloc(sizeof(*s) * (len + 1));
        i = 0;
        while (len > i)
        {
                dest[i] = s[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

int main(void)
{
	char temp[6];
	int i;
	int bs = 5;
	int fd = open("file4", O_RDONLY);
	int readcount = read(fd, temp, bs);
	printf("%d\n", readcount);
	printf("%s\n", temp);
	printf("first read finished\n");
	while (temp[i])
		i++;
	printf("%d", i);
/*	readcount = read(fd, temp, bs);
	printf("%d\n", readcount);
	printf("%s\n", temp);
	printf("second read finished\n");
	readcount = read(fd, temp, bs);
	printf("%d\n", readcount);
	printf("%s\n", temp);
	return (0);*/
}
