#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	char *line;
    int res;
	int fd = open("/tmp/gnlkiller/tests/simple", O_RDONLY);
	while (((res = get_next_line(fd,&line)) == 1))
	{
		printf("%i. - |%s|\n", res, line);
		free(line);
	}
	printf("%i. - |%s|\n", res, line);
	free(line);
    while (1 == 1)
    {
	}
	return (0);
}
