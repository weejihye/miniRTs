/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:14:40 by jwee              #+#    #+#             */
/*   Updated: 2023/05/03 16:14:41 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	double_syntax_check(char *str)
{
	int	dot_count;

	dot_count = 0;
	if (*str != '-' && *str != '+' && !ft_isdigit(*str))
		return (1);
	while (*(++str))
	{
		if (*str == '.')
		{
			if (++dot_count > 1 || !ft_isdigit(*(str + 1)))
				return (1);
			continue ;
		}
		if (!ft_isdigit(*str))
			return (1);
	}
	return (0);
}

static char	**rgb_syntax_check(char *info)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(info, ',');
	if (!temp || !temp[0] || !temp[1] || !temp[2] || temp[3])
	{
		free_double_ptr(temp);
		return (NULL);
	}
	while (temp[i])
	{
		if (ft_atoi_valid(temp[i]) < 0)
		{
			free_double_ptr(temp);
			return (NULL);
		}
		i++;
	}
	return (temp);
}

static char	**vec_syntax_check(char *info)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(info, ',');
	if (!temp || !temp[0] || !temp[1] || !temp[2] || temp[3])
	{
		free_double_ptr(temp);
		return (NULL);
	}
	while (temp[i])
	{
		if (double_syntax_check(temp[i]))
		{
			free_double_ptr(temp);
			return (NULL);
		}
		i++;
	}
	return (temp);
}

int	str_to_rgb(t_rgb *rgb, char *str)
{
	char	**temp;

	temp = rgb_syntax_check(str);
	if (!temp || !temp[0] || !temp[1] || !temp[2] || temp[3])
		return (free_double_ptr(temp));
	(*rgb).r = ft_atoi_valid(temp[0]);
	(*rgb).g = ft_atoi_valid(temp[1]);
	(*rgb).b = ft_atoi_valid(temp[2]);
	free_double_ptr(temp);
	return (0);
}

int	str_to_vec(t_vec *vec, char *str)
{
	char	**temp;

	temp = vec_syntax_check(str);
	if (!temp)
		return (print_error("value_to_vec: split fail\n"));
	(*vec).x = ft_stod(temp[0], 0.0, 1);
	(*vec).y = ft_stod(temp[1], 0.0, 1);
	(*vec).z = ft_stod(temp[2], 0.0, 1);
	if (!ft_isdouble((*vec).x) || !ft_isdouble((*vec).y)
		|| !ft_isdouble((*vec).z))
		return (free_double_ptr(temp));
	free_double_ptr(temp);
	return (0);
}
