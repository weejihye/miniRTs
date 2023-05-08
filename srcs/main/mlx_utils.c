/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:14:52 by jwee              #+#    #+#             */
/*   Updated: 2023/05/08 15:03:34 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	press_button_exit(t_objs *objs)
{
	remove_list(&objs->obj);
	write(1, "exit success\n", 13);
	exit(0);
	return (0);
}

int	press_key(int key, t_objs *objs)
{
	if (key == 53)
		press_button_exit(objs);
	else
		move_camera(key, objs);
	return (0);
}

void	draw_background(t_objs *objs, t_dot dot)
{
	double	r;
	double	g;
	t_rgb	rgb;

	r = ((double)(objs->cam.width - dot.x + 500) / (objs->cam.width - 1));
	if (r > 1)
		r = 1;
	g = ((double)(dot.y + 600) / (objs->cam.height - 1));
	if (g > 1)
		g = 1;
	rgb.b = 1 * 255;
	rgb.r = r * 255;
	rgb.g = g * 255;
	my_mlx_pixel_put(&(objs->mlx.img), dot, rgb);
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
	my_mlx_print(objs, objs->mlx);
	mlx_loop(objs->mlx.mlx);
}
