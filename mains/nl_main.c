#include <stdio.h>
#include <fcntl.h>
#include "../../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("cases/nl/01_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/02_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/03_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/04_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/05_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/06_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/07_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/08_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/09_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl/10_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
}
