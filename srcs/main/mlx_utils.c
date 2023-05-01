#include "miniRT.h"

int	press_button_exit(t_objs *objs)
{
	remove_list(&objs->obj);
	write(1, "x button was pressed\n", 21);
	system("leaks miniRT");
	exit(0);
	return (0);
}

int	press_key(t_objs *objs)
{
	objs = NULL;
	return (0);
}
