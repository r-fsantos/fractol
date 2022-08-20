/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:34:02 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/20 14:54:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_setup_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, ft_on_pressing_key, fractol);
	mlx_mouse_hook(fractol->mlx_win, ft_on_zooming, fractol);
	mlx_expose_hook(fractol->mlx_win, (void *)ft_create_img,
		fractol);
	mlx_hook(fractol->mlx_win, 17, 1L << 0, ft_should_close, fractol);
}

int	ft_on_pressing_key(int key, t_fractol *fractol)
{
	if (key == e_esc)
		ft_should_close(fractol);
	else if (it_pressed_any_arrow_key(key))
		ft_panning(key, &(fractol->img));
	ft_calculate_fractal(&(fractol->img), fractol->type);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img, 0, 0);
	return (0);
}

int	ft_on_zooming(int key, int x, int y, t_fractol *fractol)
{
	float	viewport_range;

	viewport_range = fractol->img.xmax - fractol->img.xmin;
	if (key == e_zooming_in)
	{
		fractol->img.xmin += 0.1 * viewport_range;
		fractol->img.xmax -= 0.1 * viewport_range;
		fractol->img.ymin += 0.1 * viewport_range;
		fractol->img.ymax -= 0.1 * viewport_range;
	}
	if (key == e_zooming_out)
	{
		fractol->img.xmin -= 0.1 * viewport_range;
		fractol->img.xmax += 0.1 * viewport_range;
		fractol->img.ymin -= 0.1 * viewport_range;
		fractol->img.ymax += 0.1 * viewport_range;
	}
	if (key == e_zooming_in || key == e_zooming_out)
		ft_following_mouse(&(fractol->img), x, y);
	ft_create_img(fractol);
	// ft_calculate_fractal(&(fractol->img), fractol->type);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img, 0, 0);
	return (0);
}

void	ft_following_mouse(t_data *img, int x, int y)
{
	img->step = (img->xmax - img->xmin) / WIN_SIDE;
	img->xmin += (x - (WIN_SIDE / 2)) * img->step;
	img->xmax += (x - (WIN_SIDE / 2)) * img->step;
	img->ymin += (y - (WIN_SIDE / 2)) * img->step;
	img->ymax += (y - (WIN_SIDE / 2)) * img->step;
}
