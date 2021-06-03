all: new.c new_utils.c main.c
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=99999 new.c new_utils.c main.c
