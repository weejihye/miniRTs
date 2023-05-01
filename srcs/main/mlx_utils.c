#include "miniRT.h"

void	press_button_exit(t_obj **objs)
{
	remove_list(objs);
	write(1, "x button was pressed\n", 21);
	system("leaks miniRT");
	exit(0);
}

void	press_key(t_obj **objs)
{}