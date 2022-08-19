/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:51:16 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/19 18:39:14 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

// 	return (is_number(argv[2]) && is_number(argv[3]));
int	is_julia(int argc, char **argv)
{
	int	valid_args;

	if (argc != JULIA_NBR_ARGS)
		return (false);
	valid_args = (is_number(argv[2]) && is_number(argv[3]));
	return (valid_args);
}

void	ft_set_julia(char **argv, t_fractol *fractol)
{
	fractol->name = ft_strdup("Fract-ol Julia");
	fractol->type = e_julia;
	fractol->img.julia_c_re = ft_atod(argv[2]);
	fractol->img.julia_c_im = ft_atod(argv[3]);
}

int	ft_julia(double x, double y, double c_re, double c_im)
{
	int		iterations;
	double	tmp;

	iterations = 0;
	while (x * x + y * y <= 4 && iterations < MAX_ITERATIONS)
	{
		tmp = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = tmp;
		iterations++;
	}
	return (iterations);
}
