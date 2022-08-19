/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:52:17 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/19 18:31:38 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	it_pressed_any_arrow_key(int key)
{
	return (key == e_left || key == e_right || key == e_down || key == e_up);
}

double	ft_atod(char *number)
{
	int		sign;
	double	result;
	int		decimal_len;

	sign = 1;
	if (*number == '+' || *number == '-')
	{
		if (*number == '-')
			sign = -1;
		number++;
	}
	result = (*number - '0') * sign;
	number += 2;
	decimal_len = ft_strlen(number);
	result += ft_itod(number, decimal_len);
	return (result);
}

double	ft_itod(char *number, int number_len)
{
	double	decimal;

	decimal = ft_atoi(number);
	decimal /= pow(10, number_len);
	return (decimal);
}

int	is_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (!ft_isdigit(number[i]))
		return (false);
	i++;
	if (number[i] != '.')
		return (false);
	i++;
	if (!ft_isdigit(number[i]))
		return (false);
	while (ft_isdigit(number[i]))
		i++;
	if (number[i])
		return (false);
	return (true);
}
