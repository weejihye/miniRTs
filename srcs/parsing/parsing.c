/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/25 15:21:59 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_info(t_info *info, char ***infos)
{
	while (*infos)
	{
		if (!ft_strcmp(**infos, "C"))
			init_camera(info, *infos);
		else if (!ft_strcmp(**infos, "A"))
			init_ambient(info, *infos);
        infos++;
	}
	return (0);
}

int	parsing(t_info *info, char *file)
{
	char	***infos;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("parsing error : open file fail"));
	read_rt(fd, &infos);
	close(fd);
	init_info(info, infos);
	//for (int i = 0; infos[i]; i++)
	//	for(int j = 0; infos[i][j]; j++)
	//		printf("%s\n", infos[i][j]);
	return (0);
}

int main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	parsing(&info, argv[1]);
	return (0);
}