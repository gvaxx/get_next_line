#include "get_next_line.h"
#include <stdio.h>

int main()
{
 	char *line;
	
 	int fd = open("fat", O_RDONLY);
 	while (get_next_line(fd, &line))
 	{
  		printf("%s", line);
  		free(line);
	}
	printf("%s", line);
	free(line);
	return(1);
}