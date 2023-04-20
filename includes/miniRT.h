/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   miniRT.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jwee <jwee@student.42seoul.kr>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/03 02:37:44 by jwee			  #+#	#+#			 */
/*   Updated: 2023/04/20 15:45:33 by jwee			 ###   ########.fr	   */
/*																			*/
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

# define RATIO (double)(16.0 / 9.0)

# define X_EVENT_KEY_PRESS	   2
# define X_EVENT_KEY_release	 3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC		 53
# define KEY_Q		  12
# define KEY_W		  13
# define KEY_E		  14
# define KEY_R		  15
# define KEY_A		  0
# define KEY_S		  1
# define KEY_D		  2

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

typedef struct s_info
{
	t_cam	*cam_ptr;
}	t_info;

#endif