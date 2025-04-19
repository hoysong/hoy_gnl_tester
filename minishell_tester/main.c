#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "./minitester.h"
#include <stdio.h>

extern int	find_minishell( void );

t_info	init_info(char **argv, char **env)
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

void	run_tester(t_info *info)
{
	pid_t	pid;
	int		to_mini_fd[2];
	int		from_mini_fd[2];
	int		err_from_mini_fd[2];
	char	outputs[1024];

	pipe(to_mini_fd);
	pipe(from_mini_fd);
	pipe(err_from_mini_fd);
	pid = fork();
	if (pid) // 부모
	{
		sleep(1);
		write(to_mini_fd[1], "ls\n", 3);
		sleep(3);
		write(to_mini_fd[1], "echo hi\n", 8);
		sleep(3);
		write(to_mini_fd[1], "exit\n", 5);
		sleep(3);

		//stdin
		waitpid(pid, NULL, 0);
		int len = read(from_mini_fd[0], outputs, sizeof(outputs) - 1);
		outputs[len] = '\0';
		put_str(RED, "now_parent\n");
		printf("input: %d\n", len);
		printf("%s\n", outputs);

		//err
		len = read(err_from_mini_fd[0], outputs, sizeof(outputs) - 1);
		outputs[len] = '\0';
		put_str(RED, "now_parent\n");
		printf("input: %d\n", len);
		printf("%s\n", outputs);

	}
	else // 자식
	{
		dup2(to_mini_fd[0], 0);
		dup2(from_mini_fd[1], 1);
		dup2(err_from_mini_fd[1], 2);
		close(to_mini_fd[0]);
		close(to_mini_fd[1]);
		close(from_mini_fd[0]);
		close(from_mini_fd[1]);
		close(err_from_mini_fd[0]);
		close(err_from_mini_fd[1]);
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
