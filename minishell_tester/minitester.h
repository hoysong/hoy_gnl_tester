#ifndef MINITESTER_H
# define MINITESTER_H
# ifndef PRINT_COLORS
#  define RED "\e[1;31m"
#  define GRN "\e[1;32m"
#  define YLO "\e[1;33m"
#  define END "\e[0m"
#  define NO_COLOR ""
# define TEST_CASE "string", "string_2"
# endif


void	put_str(char *color, char *str);

#endif
