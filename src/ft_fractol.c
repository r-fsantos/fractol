/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:24:59 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/20 15:10:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_fractol_init(t_fractol *fractol)
{
	ft_bzero(fractol, sizeof(t_fractol));
	fractol->win_height = WIN_SIDE;
	fractol->win_width = WIN_SIDE;
	fractol->img.xmin = MIN_AXIS;
	fractol->img.xmax = MAX_AXIS;
	fractol->img.ymin = MIN_AXIS;
	fractol->img.ymax = MAX_AXIS;
	fractol->img.step = (MAX_AXIS - MIN_AXIS) / WIN_SIDE;
	fractol->img.julia_c_re = 0.0;
	fractol->img.julia_c_im = 0.0;
}

void	ft_panning(int key, t_data *img)
{
	if (key == e_left)
	{
		img->xmin -= 10 * img->step;
		img->xmax -= 10 * img->step;
	}
	else if (key == e_right)
	{
		img->xmin += 10 * img->step;
		img->xmax += 10 * img->step;
	}
	else if (key == e_up)
	{
		img->ymin -= 10 * img->step;
		img->ymax -= 10 * img->step;
	}
	else if (key == e_down)
	{
		img->ymin += 10 * img->step;
		img->ymax += 10 * img->step;
	}
}

void	ft_calculate_fractal(t_data *img, int type)
{
	int		iterations;
	double	x;
	double	y;

	x = img->xmin;
	while (x <= img->xmax)
	{
		y = img->ymin;
		while (y <= img->ymax)
		{
			if (type == e_mandelbrot)
				iterations = ft_mandelbrot(x, y);
			if (type == e_julia)
				iterations = ft_julia(x, y, img->julia_c_re, img->julia_c_im);
			ft_setup_colors(x, y, iterations, img);
			y += img->step;
		}
		x += img->step;
	}
}
