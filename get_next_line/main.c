#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	char *line;
	int fd = open("/dev/random", O_RDONLY);
	while (get_next_line(fd,&line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s", line);
	free(line);
	return (0);
}
