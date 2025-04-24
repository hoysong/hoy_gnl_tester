#include <stdlib.h>
#include "./minitester.h"

char	*test_case_01[] = {
	"ls | cat -e\n",
	"exit\n",
	NULL
};

char	*test_case_02[] = {
	"cmd not exist\n",
	"exit\n",
	NULL
};

char	*test_case_03[] = {
	"export test=\"echo nyan	cat\"\n",
	"$test\n",
	"exit\n",
	NULL
};

char	*test_case_04[] = {
	"pwd\n",
	"unset HOME\n",
	"cd ~\n",
	"pwd\n",
	"exit\n",
	NULL
};

char	*test_case_05[] = {
	"echo    	 hello       hi      \n",
	"exit\n",
	NULL
};

extern void	run_test_case( t_info *info, char **test_case );

void	start_prog( char **env )
{
	t_info	info;

	info.env = env;
	run_test_case(&info, test_case_01);
	run_test_case(&info, test_case_02);
	run_test_case(&info, test_case_03);
	run_test_case(&info, test_case_04);
	run_test_case(&info, test_case_05);
}

extern  int	configure(char **argv, char **env);

int	main( int argc, char **argv, char **env )
{
	if (configure(argv, env) == -1)
		return (-1);
	return (0);
}
