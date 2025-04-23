#include "minitester.h"
#include <stdio.h>

void	show_banner( void )
{
	char	*color = TURQ;
	put_color(TURQ_BG, false, "  ");put_color(TURQ_BG, false, "                                                                   ");put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "                                                                   ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ███████╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗ ██╗██████╗ ██████╗   ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ██╔════╝██╔═══██╗████╗  ██║██╔════╝ ██╔══██╗██║██╔══██╗██╔══██╗  ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ███████╗██║   ██║██╔██╗ ██║██║  ███╗██████╔╝██║██████╔╝██║  ██║  ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ╚════██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗██║██╔══██╗██║  ██║  ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ███████║╚██████╔╝██║ ╚████║╚██████╔╝██████╔╝██║██║  ██║██████╔╝  ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚═╝╚═╝  ╚═╝╚═════╝   ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ████████╗███████╗███████╗████████╗███████╗██████╗                ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗               ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "     ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝               ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "     ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗               ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "     ██║   ███████╗███████║   ██║   ███████╗██║  ██║               ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "     ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝ _minishell    ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ, true, "                                                                   ");      put_color(TURQ_BG, false, "  \n");
	put_color(TURQ_BG, false, "  ");put_color(TURQ_BG, false, "                                                                   ");put_color(TURQ_BG, false, "  \n");
	printf("\n");
}
