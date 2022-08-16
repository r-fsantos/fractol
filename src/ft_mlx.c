/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:40:59 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/15 21:19:33 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	ft_setup_hooks(t_fractol *fractol);
static int	ft_on_pressing_key(int key, t_fractol *fractol);
static int	ft_on_zooming(int key, int x, int y, t_fractol *fractol);
static void	ft_following_mouse(t_data *img, int x, int y);

void	ft_mlx_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		ft_puterror(e_mlx_bad_init, fractol);
	fractol->mlx_win = mlx_new_window(fractol->mlx, fractol->win_width,
			fractol->win_height, fractol->name);
	if (!fractol->mlx_win)
		ft_puterror(e_mlx_bad_init, fractol);
	fractol->img.img = mlx_new_image(fractol->mlx, 700, 700);
	if (!fractol->img.img)
		ft_puterror(e_mlx_bad_init, fractol);
	fractol->img.addr = mlx_get_data_addr(
			fractol->img.img,
			&(fractol->img.bits_per_pixel),
			&(fractol->img.line_lenght),
			&(fractol->img.endian)
			);
	if (!fractol->img.addr)
		ft_puterror(e_mlx_bad_init, fractol);
	ft_calculate_fractal(&(fractol->img), fractol->type);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img, 0, 0);
	ft_setup_hooks(fractol);
	mlx_loop(fractol->mlx);
}

// TODO: Add macros for mlx_hook!
static void	ft_setup_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, ft_on_pressing_key, fractol);
	mlx_mouse_hook(fractol->mlx_win, ft_on_zooming, fractol);
	mlx_expose_hook(fractol->mlx_win, (void *)ft_calculate_fractal,
		fractol->mlx);
	mlx_hook(fractol->mlx_win, 17, 1L << 0, ft_should_close, fractol);
}

/**
 * TODO:
 * 		Refactor ft_calculate_fractal and mlx_put_image_to_window to some kind
 * 		of reload_fractal()
 **/
static int	ft_on_pressing_key(int key, t_fractol *fractol)
{
	if (key == e_esc)
		ft_should_close(fractol);
	else if (it_pressed_any_arrow_key(key))
		ft_panning(key, &(fractol->img));
	else
	{
		printf("pressing key: %d\n", key);
	}
	ft_calculate_fractal(&(fractol->img), fractol->type);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img, 0, 0);
	return (0);
}

static int	ft_on_zooming(int key, int x, int y, t_fractol *fractol)
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
	ft_following_mouse(&(fractol->img), x, y);ft_calculate_fractal(&(fractol->img), fractol->type);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img, 0, 0);
	return (printf("Clicou com o mouse\nkey: %d\nx: %d  y: %d\n", key, x, y));
}

static void	ft_following_mouse(t_data *img, int x, int y)
{
	img->step = (img->xmax - img->xmin) / WIN_SIDE;
	img->xmin += (x - (WIN_SIDE / 2)) * img->step;
	img->xmax += (x - (WIN_SIDE / 2)) * img->step;
	img->ymin += (y - (WIN_SIDE / 2)) * img->step;
	img->ymax += (y - (WIN_SIDE / 2)) * img->step;
}

// adicionar mlx_destroy_display; trocar a ordem!!!
int	ft_should_close(t_fractol *fractol)
{
	if (fractol)
	{
		mlx_destroy_image(fractol->mlx, fractol->img.img);
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		free(fractol->mlx);
	}
	exit(0);
	return (0);
}
