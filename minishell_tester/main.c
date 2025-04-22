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
	"ls | cat -e\n",
	"exit\n",
	NULL
};

typedef struct s_fds
{
	int		to_shell[2];
	int		from_shell[2];
	int		err_from_shell[2];
}	t_fds;

typedef struct s_info
{
	t_fds	mini_fd;
	t_fds	bash_fd;
	t_fds	*fd_now;
	char	**env;
	char	mini_display_line;
}	t_info;

static inline void pipe_fd(t_info *info)
{
	pipe(info->bash_fd.to_shell);
	pipe(info->bash_fd.from_shell);
	pipe(info->bash_fd.err_from_shell);
	pipe(info->mini_fd.to_shell);
	pipe(info->mini_fd.from_shell);
	pipe(info->mini_fd.err_from_shell);
}

static inline void	close_fd(t_info *info)
{
	close(info->mini_fd.err_from_shell[0]);
	close(info->mini_fd.err_from_shell[1]);
	close(info->mini_fd.from_shell[0]);
	close(info->mini_fd.from_shell[1]);
	close(info->mini_fd.to_shell[0]);
	close(info->mini_fd.to_shell[1]);
	close(info->bash_fd.err_from_shell[0]);
	close(info->bash_fd.err_from_shell[1]);
	close(info->bash_fd.from_shell[0]);
	close(info->bash_fd.from_shell[1]);
	close(info->bash_fd.to_shell[0]);
	close(info->bash_fd.to_shell[1]);
}

void	select_shell(t_info *info, char *shell_name, char **test_case)
{
	pid_t	pid;
	char	*argv[3] = 
	{
		shell_name,
		NULL
	};

	pid = fork();
	if (pid)
	{
		while (*test_case)
		{
			usleep(1000 * 500);
			write(info->fd_now->to_shell[1], *test_case, strlen(*test_case));
			test_case++;
		}
		waitpid(pid, NULL, 0);
	}
	else
	{
		dup2(info->fd_now->to_shell[0], 0);
		dup2(info->fd_now->from_shell[1], 1);
		dup2(info->fd_now->err_from_shell[1], 2);
		execve(shell_name, argv, info->env);
		exit(0);
	}
}

void	diff_fd(t_info *info)
{
	char	outputs[1024];
	ssize_t	len = 0;

	while (1)
	{
		len = read(info->bash_fd.from_shell[0], outputs, sizeof(outputs));
		outputs[len] = '\0';
		printf("%s", outputs);
		if (len < sizeof(outputs))
			break ;
	}

	while (1)
	{
		printf("hi\n");
		write(info->bash_fd.err_from_shell[1], "", strlen(""));
		len = read(info->bash_fd.err_from_shell[0], outputs, sizeof(outputs));
		printf("hi\n");
		outputs[len] = '\0';
		printf("%s", outputs);
		if (len < sizeof(outputs))
			break ;
	}
}

void	get_first_display_line(t_info *info, char *shell_name)
{
	char	buf[1024];

	pipe_fd(info);
	close_fd(info);
}

static void	run_test_case(t_info *info, char **test_case)
{
	pipe_fd(info);
	printf("RUN SHELL...\n");
	info->fd_now = &(info->bash_fd);
	select_shell(info, "/usr/bin/bash", test_case);
	info->fd_now = &(info->mini_fd);
	select_shell(info, "../../minishell", test_case);
	printf("DONE!\n");
	printf("diff fd now\n");
	diff_fd(info);
	close_fd(info);
}

static void	start_prog( char **env )
{
	t_info	info;
	char	**test_case;

	info.env = env;
	//get_first_display_line(&info, "../../minishell");
	//get_first_display_line(&info, "/usr/bin/bash");
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
