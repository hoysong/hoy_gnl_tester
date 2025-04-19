#include <stdio.h>
#include <fcntl.h>
#include "../../get_next_line.h"

int	main(void)
{
	char	*str;

	str = get_next_line(-1);
	printf("%s", str);
	free(str);

	str = get_next_line(1000);
	printf("%s", str);
	free(str);
}
