/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:29:37 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/16 08:50:10 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

static void	ft_mlx_pixel_put(t_data *img, int x, int y, int color);

void	ft_setup_colors(double x, double y, int iterations, t_data *img)
{
	double	color;

	color = 0x000000;
	if (iterations < MAX_ITERATIONS)
		color = 0xFFF + iterations * 30.05;
	ft_mlx_pixel_put(img, (x - img->xmin) / img->step,
		(y - img->ymin) / img->step, color);
}

static void	ft_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
