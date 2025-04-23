#ifndef MINITESTER_H
# include <stdbool.h>
# define MINITESTER_H

# ifndef PRINT_COLORS

#  define RED "31"
#  define RED_BG "41"

#  define GRN "32"
#  define GRN_BG "42"

#  define PUR "35"
#  define PUR_BG "45"

#  define BLU "34"
#  define BLU_BG "44"

# define WHITE_BG "47"

#  define END "\e[0m"

#  define TURQ "36"
#  define TURQ_BG "46"

# define TEST_CASE "string", "string_2"
# define TEST_CASE_2 {"string", "string_2"}
# endif

//typedef struct s_info
//{
//	char	**argv;
//	char	**env;
//}	t_info;

/*	put_color.
 *	color options.
 *	RED.
 *	GRN.
 *	YLO.
 *	END.
 *	NO_COLOR.
 */

void	put_color(char *color, bool bold, char *str);
int		get_file_type(char *argv);

#endif
