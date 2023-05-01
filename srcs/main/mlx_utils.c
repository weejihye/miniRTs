#include "miniRT.h"

int	press_button_exit(t_objs *objs)
{
	remove_list(&objs->obj);
	write(1, "x button was pressed\n", 21);
	exit(0);
	return (0);
}

int	press_key(int key, t_objs *objs)
{
	if (key == 53)
		press_button_exit(objs);
	return (0);
}
