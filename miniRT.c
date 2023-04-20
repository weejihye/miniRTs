/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:45:37 by jwee              #+#    #+#             */
/*   Updated: 2023/04/14 00:16:49 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(void)
{
    t_mlx mlx;
    int i, j, k;

    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 600, 400, "miniRT");
    mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, 600, 400);
    mlx.img.addr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
    for (int j = cam.)
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
    mlx_loop(mlx.mlx_ptr);
    return 0;
}