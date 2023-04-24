/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:58:43 by jwee              #+#    #+#             */
/*   Updated: 2023/04/24 16:31:03 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	word_count_space(const char *src)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] && ft_isspace(src[i]))
			i++;
		while (src[i] && !ft_isspace(src[i]))
		{
			i++;
			if (!src[i] || ft_isspace(src[i]))
				wc++;
		}
	}
	return (wc);
}

char	**free_all_space(char **result, int i)
{
	int	j;

	j = 0;
	while (j++ <= i)
		free(result[j]);
	return (NULL);
}

char	**split_space(char **result, const char *src, int wc)
{
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (wc + 1));
	if (!result)
		return (NULL);
	result[wc] = NULL;
	while (src[i])
	{
		while (src[i] && ft_isspace(src[i]))
			i++;
		if (!src[i])
			break ;
		start = i;
		while (src[i] && !ft_isspace(src[i]))
			i++;
		result[j++] = ft_substr(src, start, i - start);
		if (!result[j - 1])
			return (free_all_space(result, j - 1));
	}
	return (result);
}

char	**ft_split_spaces(const char *src)
{
	int		wc;
	char	**result;

	if (!src)
		return (NULL);
	result = NULL;
	wc = word_count_space(src);
	result = split_space(result, src, wc);
	return (result);
}
