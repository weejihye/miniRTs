/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:14:49 by jwee              #+#    #+#             */
/*   Updated: 2023/05/03 16:14:49 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_objs	objs;

	(void)argc;
	if (parsing(&objs, argv[1]))
		return (1);
	my_mlx_init(objs, &objs.mlx);
	draw(objs.mlx, &objs);
	my_mlx_handle(&objs);
	system("leaks miniRT");
	return (0);
}
