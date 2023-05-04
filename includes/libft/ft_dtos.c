/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:20:38 by jwee              #+#    #+#             */
/*   Updated: 2023/05/04 18:48:15 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_result(char **str)
{
	char	temp;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(*str);
	while (i < (length + 1) / 2)
	{
		temp = (*str)[i];
		(*str)[i] = (*str)[length - i - 1];
		(*str)[length - i - 1] = temp;
		i++;
	}
}

void	int_to_string(double origin, int number, char **str)
{
	int	i;
	int	negative;

	negative = (origin < 0);
	i = 0;
	if (negative)
		number *= -1;
	if (number == 0)
		(*str)[i++] = '0';
	while (number > 0)
	{
		(*str)[i++] = '0' + number % 10;
		number /= 10;
	}	
	if (negative)
		(*str)[i++] = '-';
	(*str)[i] = '\0';
	swap_result(str);
}

int	get_int_digit(int integer, double number)
{
	int	result;
	int	temp;

	result = 0;
	temp = integer;
	result = (number <= 0 || integer == 0);
	while ((integer > 0 && temp > 0) || (integer < 0 && temp < 0))
	{
		temp /= 10;
		result++;
	}
	if (number < 0 && integer == 0)
		result++;
	return (result);
}

void	deci_to_string(double number, int int_digit, char **str)
{
	int		decimal_digit;
	int		i;
	int		digit;
	double	decimal;

	decimal = number - (int)number;
	i = 0;
	decimal_digit = 3;
	if (decimal_digit > 0)
	{
		(*str)[int_digit] = '.';
		if (number < 0)
			decimal *= -1;
		while (i < decimal_digit)
		{
			decimal *= 10;
			digit = (int)decimal;
			(*str)[int_digit + i + 1] = '0' + digit;
			decimal -= digit;
			i++;
		}
	}
}

char	*ft_dtos(double number)
{
	const int	integer = (int)number;
	const int	int_digit = get_int_digit(integer, number);
	char		*str;

	str = malloc(int_digit + 5);
	if (str == NULL)
		return (NULL);
	int_to_string(number, integer, &str);
	deci_to_string(number, int_digit, &str);
	return (str);
}
