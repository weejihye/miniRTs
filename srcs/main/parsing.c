/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:35:52 by jwee              #+#    #+#             */
/*   Updated: 2023/04/24 23:17:34 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"

int	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "Error\n", 6);
	exit(1);
}

void	get_infos(char **temp, char ****infos, int i)
{
	(*infos) = malloc(sizeof(char **) * (i + 1));
	if (!*infos)
		exit(print_error("infos malloc fail"));
	(*infos)[i] = NULL;
	i = -1;
	while (temp[++i])
		(*infos)[i] = ft_split_spaces(temp[i]);
}

int	read_rt(int fd, char ****infos)
{
	char	*buff;
	char	*temp[100];
	int		i;

	i = 0;
	ft_memset(temp, 0, sizeof(char *) * 100);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (*buff == '\n')
		{
			free(buff);
			continue ;
		}
		temp[i++] = buff;
		temp[i - 1][ft_strchr(buff, '\n') - 1] = 0;
	}
	get_infos(temp, infos, i);
	return (0);
}

int	vec_syntax_check(char *info)
{
	int	dot_count;
	int	comma_count;

	dot_count = 0;
	comma_count = 0;
	if ((!ft_isdigit(*info) && *info != '-')
		|| (*info == '-' && !ft_isdigit(*(info + 1))))
		return (print_error("false start\n"));
	while (*(++info))
	{
		if ((!ft_isdigit(*info) && *info != '.' && *info != ',' )
			|| ((*info == '.' || *info == ',') && !ft_isdigit(*(info + 1))))
			return (print_error("syntax check fail : invalid input\n"));
		if (*info == '.')
			if (++dot_count > 1)
				return (print_error("more than 1 dot\n"));
		if (*info == ',')
		{
			comma_count++;
			dot_count = 0;
		}
	}
	if (comma_count != 2)
		return (print_error("invalid number of comma\n"));
	return (0);
}

int	init_camera(t_info *info, char **infos)
{
	int		i;
	char	**viewpoint_str;

	if (!infos[1] || !infos[2] || !infos[3] || infos[4])
		return (print_error("number of properties is invalid\n"));
	vec_syntax_check(infos[1]);
	vec_syntax_check(infos[2]);
	viewpoint_str = ft_split(infos[1], ',');
	info->cam = malloc(sizeof(t_cam));
	info->cam->origin.x = ft_stod(viewpoint_str[0], 0.0, 1);
	info->cam->origin.y = ft_stod(viewpoint_str[1], 0.0, 1);
	info->cam->origin.z = ft_stod(viewpoint_str[2], 0.0, 1);
	info->cam->fov = ft_atoi_valid(infos[3]);
	if (!ft_isdouble(info->cam->origin.x) || !ft_isdouble(info->cam->origin.y)
		|| !ft_isdouble(info->cam->origin.z) || info->cam->fov < 0
		|| info->cam->fov > 180)
		return (print_error("out of range\n"));
	return (0);
}

int	init_info(t_info *info, char ***infos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	for (int i = 0; infos[i]; i++)
	{
		for (int j = 0; infos[i][j]; j++)
		{
			if (!ft_strcmp("C", infos[i][j]))
				init_camera(info, infos[i]);
		}
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