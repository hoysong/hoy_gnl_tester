#include <stdio.h>
#include <fcntl.h>
#include "../../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("cases/no_nl/01_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/02_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/03_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/04_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/05_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/06_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/07_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/08_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/09_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}

	fd = open("cases/no_nl/10_no_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		 
		printf("%s", str);
		free(str);
	}
}
