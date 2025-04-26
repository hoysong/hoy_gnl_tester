#include <stdlib.h>
#include "./minitester.h"

/* README. */
/*
 * you can make your own test cases easily with this main.c.
 * some test cases doesn't works for your tiny shell.
 * but I think it doesn't mean your shell is wrong.
 * cuz subject asking for build your own minishell.
 * this is why this tester doesn't evaluate your shell.
 * this tester builder existing for just showing differences of your shell and bash.
 */

char	*test_case_01[] = {
	"ls | cat -e\n",
	"exit\n",
	NULL
};

char	*test_case_02[] = {
	"cmd not exist\n",
	"echo $?\n",
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

char	*test_case_06[] = {
	"\"e\"c\"h\"o t\"h\"i\"s\" \"is\" e\"cho\"!\n",
	"\n",
	"exit\n",
	NULL
};

char	*test_case_07[] = {
	"echo $?\n",
	"exit\n",
	NULL
};

char	*test_case_08[] = {
	"ls -la | cat -e\n",
	"exit\n",
	NULL
};

/* rediractions test. */
char	*test_case_09[] = {
	"cd ./test_files/\n",
	"pwd\n",
	"echo hi > test_1\n",
	"echo hi > test_2\n",
	"cat test_1 -e\n",
	"cat test_2 -e\n",
	"echo append >> test_1\n",
	"echo append >> test_2\n",
	"cat test_1 -e\n",
	"cat test_2 -e\n",
	"rm test_1 test_2\n",
	"ls -la\n",
	"exit\n",
	NULL
};

char	*test_case_10[] = {
	"cd test_files\n",
	"echo this is test_1 > test_1\n",
	"echo this is test_2 > test_2\n",
	"echo this is test_3 > test_3\n",
	"cat < test_1 < test_2 < test_3\n",
	"< test_1 < test_2 < test_3 cat\n",
	"< test_1 < test_2 cat < test_3\n",
	"< test_1 cat < test_2 < test_3\n",
	"rm test_1 test_2 test_3\n",
	"ls -la\n",
	"exit\n",
	NULL
};

char	*test_case_11[] = {
	"cd test_files\n",
	"echo this is test_1 > test_1\n",
	"echo this is test_2 > test_2\n",
	"echo this is test_3 > test_3\n",
	"cat<test_1<test_2<test_3\n",
	"<test_1<test_2<test_3 cat\n",
	"<test_1<test_2 cat<test_3\n",
	"<test_1 cat<test_2<test_3\n",
	"rm test_1 test_2 test_3\n",
	"ls -la\n",
	"exit\n",
	NULL
};

char	*test_case_12[] = {
	"cd ./test_files/\n",
	"pwd\n",
	"cat << EOF > heredoc_test\n",
	"this\n",
	"is\n",
	"eof\n",
	"EOF\n",
	"cat ./heredoc_test\n",
	"rm ./heredoc_test\n",
	"exit\n",
	NULL
};

char	*test_case_14[] = {
	"echo hi\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e\
	|wc\n",
	"exit\n",
	NULL
};

char	*test_case_15[] = {
	"cd ./test_files\n",

	"cat file_not_exist\n",
	"echo $?\n",
	"echo $?\n",

	"cat < <\n",
	"echo $?\n",
	"echo $?\n",

	"./test_files/\n",
	"echo $?\n",
	"echo $?\n",

	"cmd_not_exist\n",
	"echo $?\n",
	"echo $?\n",

	"unset PATH\n",
	"cat ./main.c\n",
	"echo $?\n",
	"echo $?\n",

	"exit\n",
	NULL
};

char	*test_case_16[] = {
	"cd ./test_files\n",

	"cat file_not_exist\n",
	"$?\n",
	"$?\n",

	"cat < <\n",
	"$?\n",
	"$?\n",

	"./test_files/\n",
	"$?\n",
	"$?\n",

	"cmd_not_exist\n",
	"$?\n",
	"$?\n",

	"unset PATH\n",
	"cat ./main.c\n",
	"$?\n",
	"$?\n",

	"exit\n",
	NULL
};

char	*test_case_17[] = {
	"cd ./test_files\n",

	"echo this_is_file_3 > file_1 > file_2 > file_3\n",

	"echo show file_3 \n",
	"cat file_3\n",

	"echo show file_2 \n",
	"cat file_2\n",

	"echo show file_1\n",
	"cat file_1\n",

	"echo this_is_file_2 > file_2\n",
	"echo this_is_file_1 > file_1\n",

	"cat file_1 < file_2 < file_3\n",
	"cat < file_1 file_2 < file_3\n",
	"cat < file_1 < file_2 file_3\n",
	"< file_1 cat < file_2 file_3\n",
	"< file_1 < file_2 cat file_3\n",

	"rm file_1 file_2 file_3\n",

	"exit\n",
	NULL
};

char	*test_case_18[] = {
	"export\n",
	"exit\n",
	NULL
};

char	*test_case_19[] = {
	"env\n",
	"exit\n",
	NULL
};

char	*test_case_20[] = {
	"SIGQUIT\n",
	"echo $?\n",
	"exit\n",
	NULL
};

char	*test_case_21[] = {
	"SIGINT\n",
	"echo $?\n",
	"exit\n",
	NULL
};

char	*test_case_22[] = {
	"echo '\"$USER\"' is \"$USER\"\n",
	"echo '$'USER also $USER\n",
	"echo $\"USER\" also $USER\n",
	"echo $U\"S\"ER also \"$USER\"\n",
	"echo $\"\"USER\"\" also \"$USER\"\n",
	"echo a$USER also $USER\n",
	"echo $USER\"a\" also $USER\n",
	"echo a$USER\"a\" also $USER\n",
	"echo A$USER$USER\n",
	"echo $USER\"A\"$USER\n",
	"echo A$USER\"A\"$USER\"\"\n",
	"echo \"\"$USER\"\"$USER\"\"\n",
	"echo \"'$USER'$USER'\"\n",
	"echo \"A$USERA$USERA\"\n",
	"echo ''\"A$USERA$USERA\"''\n",
	"echo ''\"''$USER'$USER''\"''\n",
	"exit\n",
	NULL
};

char	*test_case_23[] = {
	"export TESTER_LOCATION=$PWD\n"
	"cd ../../\n"
	"export PATH=$PWD:$PATH\n",
	"echo $PATH\n",
	"minishell\n"
	"exit 42\n",
	"echo $?\n",
	"cd $TESTER_LOCATION\n",
	"minishell\n"
	"exit 42\n",
	"echo $?\n",
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
	run_test_case(&info, test_case_06);
	run_test_case(&info, test_case_07);
	run_test_case(&info, test_case_08);
	run_test_case(&info, test_case_09);
	run_test_case(&info, test_case_10);
	run_test_case(&info, test_case_11);
	run_test_case(&info, test_case_14);
	run_test_case(&info, test_case_15);
	run_test_case(&info, test_case_16);
	run_test_case(&info, test_case_17);
	run_test_case(&info, test_case_18);
	run_test_case(&info, test_case_19);
	run_test_case(&info, test_case_20);
	run_test_case(&info, test_case_21);
	run_test_case(&info, test_case_22);
	run_test_case(&info, test_case_23);
}

extern  int	configure(char **argv, char **env);

int	main( int argc, char **argv, char **env )
{
	if (configure(argv, env) == -1)
		return (-1);
	return (0);
}
