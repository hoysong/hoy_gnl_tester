#include "minitester.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

extern int	find_minishell(void);

/* easy test. */
char	*test_case_01[] = {
	"ls\n",
	"ls | cat -e\n",
	"exit\n",
	NULL
};

typedef struct s_info
{
	int		to_shell[2];
	int		from_shell[2];
	int		err_from_shell[2];
	char	**env;
}	t_info;

static inline void pipe_fd(t_info *info)
{
	pipe(info->to_shell);
	pipe(info->from_shell);
	pipe(info->err_from_shell);
}

static inline void	close_fd(t_info *info)
{
	close(info->err_from_shell[0]);
	close(info->err_from_shell[1]);
	close(info->from_shell[0]);
	close(info->from_shell[1]);
	close(info->to_shell[0]);
	close(info->to_shell[1]);
}

void	select_shell(t_info *info, char *shell_name, char **test_case)
{
	pid_t	pid;
	char	*argv[3] = 
	{
		shell_name,
		NULL
	};

	pipe_fd(info);
	pid = fork();
	if (pid)
	{
		while (*test_case)
		{
			usleep(1000 * 500);
			write(info->to_shell[1], *test_case, strlen(*test_case));
			test_case++;
		}
		waitpid(pid, NULL, 0);
	}
	else
	{
		dup2(info->to_shell[0], 0);
		dup2(info->from_shell[1], 1);
		dup2(info->err_from_shell[1], 2);
		execve(shell_name, argv, info->env);
		exit(0);
	}
}

void	diff_fd(t_info *info)
{
}

static void	run_test_case(t_info *info, char **test_case)
{
	printf("RUN SHELL...\n");
	select_shell(info, "/usr/bin/bash", test_case);
	close_fd(info);
	select_shell(info, "../../minishell", test_case);
	close_fd(info);
	printf("DONE!\n");
}

static void	start_prog( char **env )
{
	t_info	info;
	char	**test_case;

	info.env = env;
	test_case = test_case_01;
	run_test_case(&info, test_case);
}

int	main(int argc, char **argv, char **env)
{
	if (find_minishell() == -1)
		return (-1);
	else
		start_prog(env);
}
