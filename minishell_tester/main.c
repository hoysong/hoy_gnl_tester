#include "minitester.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

extern int	find_minishell(void);
extern void	show_banner( void );
extern void	test_put_color( void );

/* easy test. */
char	*test_case_01[] = {
	"ls | cat -e\n",
	"exit\n",
	NULL
};

//char	*test_case_01[] = {
//	"cd fuck\n",
//	"exit\n",
//	NULL
//};

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

static void	select_shell(t_info *info, char *shell_name, char **test_case)
{
	pid_t	pid;
	char	*argv[2] = {
		shell_name,
		NULL
	};

	pid = fork();
	if (pid)
	{
		while (*test_case)
		{
			usleep(1000 * 270);
			write(info->fd_now->to_shell[1], *test_case, strlen(*test_case));
			test_case++;
		}
		write(info->fd_now->to_shell[1], "", strlen(""));
		waitpid(pid, NULL, 0);
		/*write eof*/
		write(info->fd_now->err_from_shell[1], "", strlen(""));
		write(info->fd_now->from_shell[1], "", strlen(""));
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

static void	show_fd(t_fds *fds)
{
	char	outputs[1024];
	ssize_t	len = 0;

	while (1)
	{
		len = read(fds->from_shell[0], outputs, sizeof(outputs));
		outputs[len] = '\0';
		printf("%s", outputs);
		if (len < sizeof(outputs))
			break ;
	}

	while (1)
	{
		len = read(fds->err_from_shell[0], outputs, sizeof(outputs));
		outputs[len] = '\0';
		printf("%s", outputs);
		if (len < sizeof(outputs))
			break ;
	}

	printf("\n");
}

static void	diff_fd(t_info *info)
{
	put_color(BLU_BG, true, " ");
	put_color(BLU, true, " bash outputs\n");
	show_fd(&info->bash_fd);

	put_color(BLU_BG, true, " ");
	put_color(BLU, true, " mini outputs\n");
	show_fd(&info->mini_fd);
}

static void	get_first_display_line(t_info *info, char *shell_name)
{
	char	buf[1024];

	pipe_fd(info);
	close_fd(info);
}

static void	run_test_case(t_info *info, char **test_case)
{
	char	**test_ptr = test_case;

	put_color(TURQ_BG, true, "Test case is...\n");
	while (*test_ptr)
	{
		put_color(TURQ, true, *test_ptr);
		test_ptr++;
	}
	printf("\n");
	pipe_fd(info);
	put_color(TURQ, true, "Testing...\n");

	info->fd_now = &(info->bash_fd);
	select_shell(info, "/usr/bin/bash", test_case);

	info->fd_now = &(info->mini_fd);
	select_shell(info, "../../minishell", test_case);

	put_color(TURQ, true, "DONE!\n");
	diff_fd(info);
	close_fd(info);
}

static void	start_prog( char **env )
{
	t_info	info;
	char	**test_case;

	info.env = env;
	run_test_case(&info, test_case_01);
}

int	main(int argc, char **argv, char **env)
{
	system("clear");
	show_banner();
	put_color(TURQ_BG, false, "Finding minishell...\n");
	if (find_minishell() == -1)
		return (-1);
	else
		start_prog(env);
}
