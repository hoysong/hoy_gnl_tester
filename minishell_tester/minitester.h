#ifndef MINITESTER_H
# define MINITESTER_H

# ifndef PRINT_COLORS
#  define RED "\e[1;31m"
#  define GRN "\e[1;32m"
#  define YLO "\e[1;33m"
#  define END "\e[0m"
#  define NO_COLOR ""
# define TEST_CASE "string", "string_2"
# define TEST_CASE_2 {"string", "string_2"}
# endif

typedef struct s_info
{
	char	**argv;
	char	**env;
}	t_info;

void	put_str(char *color, char *str);

#endif
