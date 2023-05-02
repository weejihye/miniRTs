#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_objs	objs;

	(void)argc;
	if (parsing(&objs, argv[1]))
		return (1);
	my_mlx_init(objs, &objs.mlx);
	draw(objs.mlx, &objs);
	mlx_put_image_to_window(objs.mlx.mlx, objs.mlx.win, objs.mlx.img.img, 0, 0);
	my_mlx_handle(&objs);
	mlx_loop(objs.mlx.mlx);
	system("leaks miniRT");
	return (0);
}