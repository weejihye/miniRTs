/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:58:43 by jwee              #+#    #+#             */
/*   Updated: 2023/04/27 23:57:56 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	word_count(const char *src, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] && src[i] == c)
			i++;
		while (src[i] && src[i] != c)
		{
			i++;
			if (!src[i] || src[i] == c)
				wc++;
		}
	}
	return (wc);
}

char	**free_all(char **result, int i)
{
	int	j;

	j = 0;
	while (j++ <= i)
		free(result[j]);
	return (NULL);
}

static char	**split_word(char **result, const char *src, char c, int wc)
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
		while (src[i] && src[i] == c)
			i++;
		if (!src[i])
			break ;
		start = i;
		while (src[i] && src[i] != c)
			i++;
		result[j++] = ft_substr(src, start, i - start);
		if (!result[j - 1])
			return (free_all(result, j - 1));
	}
	return (result);
}

char	**ft_split(const char *src, char c)
{
	int		wc;
	char	**result;

	if (!src)
		return (NULL);
	result = NULL;
	wc = word_count(src, c);
	result = split_word(result, src, c, wc);
	return (result);
}
