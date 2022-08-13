/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:47:36 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/13 17:41:03 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	is_mandelbrot(char *str)
{
	return (!ft_strcmp(str, "mandelbrot"));
}

void	ft_set_mandelbrot(t_fractol *fractol)
{
	fractol->name = ft_strdup("Mandelbrot");
	fractol->type = e_mandelbrot;
}

int	ft_mandelbrot(double x, double y)
{
	int		iterations;
	double	tmp;
	double	c_re;
	double	c_im;
	
	iterations = 0;
	c_re = x;
	c_im = y;
	while (x * x + y * y <= 4 && iterations < MAX_ITERATIONS)
	{
		tmp  = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = tmp;
		iterations++;
	}
	return (iterations);
}
