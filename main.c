#include "get_next_line.h"
int main (int argc, char **argv)
{

	if (argc == 2)
	{
		char **line;
		line = malloc(10 * sizeof(char*));
		int fd = open(argv[2], O_RDONLY);
		while (get_next_line(fd,line) == 1)
			printf("- %s", *line);
		return (0);
	}else
	{
		char **line;
		line = malloc(10 *sizeof(char*));
		int fd = open("/tmp/test.txt", O_RDONLY);
		while (get_next_line(fd, line) == 1)
		{
				printf("- |%s|", *line);
		}
		return (0);
	}
}
