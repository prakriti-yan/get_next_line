#include "get_next_line.h"
#include "./libft/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *ar[4];
	int fd;
	int i;

	i = 0;
	fd = open("file", O_RDWR);
	while (get_next_line(fd, &ar[i]) > 0)
	{
		i++;
	}
	printf("%s\n", ar[3]);
}
