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

void	my_mlx_init(t_objs objs, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, objs.cam.width,
			objs.cam.height, "miniRT");
	mlx->img.img = mlx_new_image(mlx->mlx, objs.cam.width, objs.cam.height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
}

void	my_mlx_handle(t_objs *objs)
{
	mlx_hook(objs->mlx.win, X_EVENT_KEY_PRESS, 0, press_key, objs);
	mlx_hook(objs->mlx.win, X_EVENT_KEY_EXIT, 0, press_button_exit, objs);
}