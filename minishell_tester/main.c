#include <unistd.h>
#include <sys/stat.h>

int	main(int argc, char **argv, char **env)
{
	struct stat	s_stat;
	int	err_chk = 0;

	err_chk = stat("../minishell", &s_stat);
}
