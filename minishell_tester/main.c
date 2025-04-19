#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "./minitester.h"
#include <stdio.h>

extern int	find_minishell( void );

static t_info	init_info(char **argv, char **env)
{
	t_info	info;

	info.argv = argv;
	info.env = env;
	return (info);
}

char	**test_case( void )
{
	char	*test[]=
	{
		TEST_CASE
	};
	char	*test_2[] = TEST_CASE_2;
	return (NULL);
}

char	*test_1[] = {
	"/usr/bin/valgrind",
	"--leak-check=full",
	"--log-fd=1",
	"../../minishell",
	NULL
};

static void	run_tester(t_info *info)
{
	pid_t	pid;
	int		to_mini_fd[2];
	int		from_mini_fd[2];
	char	outputs[1024];

	pipe(to_mini_fd);
	pipe(from_mini_fd);
	pid = fork();
	if (pid) // 부모
	{
		sleep(1);
		write(to_mini_fd[1], "ls\n", 3);
		sleep(1);
		write(to_mini_fd[1], "echo hi\n", 8);
		sleep(1);
		write(to_mini_fd[1], "exit\n", 5);
		sleep(1);

		//stdin
		waitpid(pid, NULL, 0);
		int len;
		while (1)
		{
			len = read(from_mini_fd[0], outputs, sizeof(outputs) - 1);
			outputs[len] = '\0';
			printf("input_len: %d\n", len);
			printf("%s\n", outputs);
			if (len < 1023)
				break ;
		}
	}
	else // 자식
	{
		dup2(to_mini_fd[0], 0);
		dup2(from_mini_fd[1], 1);
		close(to_mini_fd[0]);
		close(to_mini_fd[1]);
		close(from_mini_fd[0]);
		close(from_mini_fd[1]);
		printf("%d\n", execve("/usr/bin/valgrind", test_1, info->env));
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{
	if (find_minishell() == -1)
		return (-1);
	t_info info = init_info(argv, env);
	run_tester(&info);
	return (0);
}
