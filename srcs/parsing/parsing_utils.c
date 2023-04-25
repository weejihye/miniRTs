#include "miniRT.h"

int	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "Error\n", 6);
	exit(1);
}