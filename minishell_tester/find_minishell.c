#include <sys/stat.h>
#include <errno.h>
#include "./minitester.h"

static int	type_chk(__mode_t mode)
{
	if ((mode & S_IFMT) == S_IFDIR)
		return (1);
	if ((mode & S_IFMT) == S_IFREG)
	{
		if ((mode & S_IXGRP) == S_IXGRP
			&& (mode & S_IXUSR) == S_IXUSR
			&& (mode & S_IXOTH) == S_IXOTH)
			return (3);
		else
			return (2);
	}
	return (0);
}

static int	get_file_type(char *argv)
{
	int			return_code;
	struct stat	stat_buf;

	return_code = 0;
	return_code = stat(argv, &stat_buf);
	if (return_code != 0)
	{
		if (errno == 20)
			return (4);
		else
			return (0);
	}
	return (type_chk(stat_buf.st_mode));
}

int	find_minishell( void )
{
	int	err_num = get_file_type("../../minishell");
	if (err_num != 3)
	{
		put_str(RED, "ERR: program minishell not found.\n");
		put_str(NO_COLOR, "├─note: locate tester repository in your minishell directory.\n");
		put_str(NO_COLOR, "└─note: your program name must be minishell.\n");
		return (-1);
	}
	else
		put_str(GRN, "minishell found!\n");
	return (1);
}
