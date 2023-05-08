/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:51:01 by pji               #+#    #+#             */
/*   Updated: 2023/05/08 15:51:54 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "vector.h"
# include "camera.h"
# include "libft/libft.h"
# include "objects.h"

# define _USE_MATH_DEFINES
# define SIZE	100

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_Z		6
# define KEY_A		0
# define KEY_X		7
# define KEY_S		1
# define KEY_C		8
# define KEY_D		2

# define KEY_Q		12
# define KEY_W		13
# define KEY_E		14
# define KEY_R		15

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_objs
{
	t_mlx	mlx;
	t_cam	cam;
	t_light	light;
	t_obj	*obj;
}	t_objs;

//[main] mlx utils
int		press_button_exit(t_objs *objs);
int		press_key(int key, t_objs *objs);
void	my_mlx_handle(t_objs *objs);
void	my_mlx_init(t_objs objs, t_mlx *mlx);
void	move_camera(int key, t_objs *objs);
void	my_mlx_print(t_objs *objs, t_mlx mlx);

//[parsing] main
int		parsing(t_objs *objs, char *file);
int		read_rt(char *file, char ****infos);
void	move_point(t_objs *objs, t_vec direction);

//[parsing] init_info
int		init_camera(t_objs *objs, char **infos, int *count);
int		init_amb(t_objs *objs, char **infos, int *count);
int		init_light(t_objs *objs, char **infos, int *count);
int		init_sphere(t_objs *objs, char **infos);
int		init_plane(t_objs *objs, char **infos);
int		init_cylinder(t_objs *objs, char **inf);

//[parsing] syntax check
int		double_syntax_check(char *str);
int		str_to_vec(t_vec *vec, char *str);
int		str_to_rgb(t_rgb *rgb, char *str);

//[parsing] utils
int		print_error(char *str);
int		free_double_ptr(char **str);
int		free_triple_ptr(char ***str);
int		check_normalized_vec(t_vec vec);

//[parsing] list_utils
void	*ft_lstnew_obj(t_obj **objs, void *content, int type);
void	*find_obj(t_obj *objs, enum e_type type);
int		remove_first_node(t_obj **objs);
int		remove_list(t_obj **objs);

//[object] draw
void	draw(t_mlx mlx, t_objs *objs);
void	draw_background(t_objs *objs, t_dot dot);
void	my_mlx_pixel_put(t_img *img, t_dot dot, t_rgb rgb);
#endif