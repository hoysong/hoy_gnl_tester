#ifndef MINITESTER_H
# define MINITESTER_H
# define MINI_LOCATION "../../minishell"

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
}	t_info;

#endif
