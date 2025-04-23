#include <stdio.h>
#include "./minitester.h"

void	put_color(char *color, bool bold, char *str)
{
	printf("\e[%d;%sm%s%s", bold, color, str, END);
}

void	test_put_color( void )
{
	put_color(RED, true, "test\n");
	put_color(RED_BG, true, "test\n");
	put_color(GRN, true, "test\n");
	put_color(GRN_BG, true, "test\n");
	put_color(BLU, true, "test\n");
	put_color(WHITE_BG, true, "test\n");
}
