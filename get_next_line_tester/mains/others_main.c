#include <stdio.h>
#include <fcntl.h>
#include "../../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("cases/others/alpha_after_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/others/dble_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/others/empty", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/others/only_nl", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/others/other_1", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/others/other_2", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/others/other_3", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
}
