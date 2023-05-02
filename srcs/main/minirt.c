#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_objs	objs;

	(void)argc; //
	if (parsing(&objs, argv[1]))
	{
		system("leaks miniRT");
		return (1);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, objs.cam.width, objs.cam.height, "miniRT");
	mlx.img.img = mlx_new_image(mlx.mlx, objs.cam.width, objs.cam.height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	draw(mlx, &objs);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, press_key, &objs);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, press_button_exit, &objs);
	mlx_loop(mlx.mlx);
	system("leaks miniRT");
	return (0);
}