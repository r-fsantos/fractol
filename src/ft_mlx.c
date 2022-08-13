/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:40:59 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/13 18:14:02 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

/**
 * TODOs:
 * 		Encapsulate window size_x and size_y into fractol "singleton" or macros
 * 		// todo: create e_mlx_win_bad_init
 */

static void	ft_setup_hooks(t_fractol *fractol);
static int	ft_on_pressing_key(int key, t_fractol *fractol);
static int	ft_on_zooming(int key, int x, int y, t_fractol *fractol);

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

static void	ft_setup_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, ft_on_pressing_key, fractol);
	mlx_mouse_hook(fractol->mlx_win, ft_on_zooming, fractol);
	mlx_expose_hook(fractol->mlx_win, (void *)ft_calculate_fractal,
		fractol->mlx);
	mlx_hook(fractol->mlx_win, 17, 1L << 0, ft_should_close, fractol);
}

static int	ft_on_pressing_key(int key, t_fractol *fractol)
{
	if (key == 53)
	{
		ft_should_close(fractol);
	}
	else
	{
		printf("pressing key: %d\n", key);
	}
	return (0);
}

static int	ft_on_zooming(int key, int x, int y, t_fractol *fractol)
{
	return (printf("%s: Clicou com o mouse\nkey: %d\nx: %d  y: %d\n",
			fractol->name, key, x, y));
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
