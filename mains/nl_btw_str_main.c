#include <stdio.h>
#include <fcntl.h>
#include "../../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("cases/nl_btw_str/01_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/02_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/03_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/04_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/05_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/06_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/07_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/08_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}

	fd = open("cases/nl_btw_str/09_nl_btw_str", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
}
