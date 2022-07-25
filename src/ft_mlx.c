/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:40:59 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/25 10:08:29 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_mlx_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		ft_puterror(e_mlx_bad_init);
	fractol->mlx_win = mlx_new_window(fractol->mlx, 700, 700, fractol->name);
	if (!fractol->mlx_win)
		ft_puterror(e_mlx_bad_init);
	fractol->img.img = mlx_new_image(fractol->mlx, 700, 700);
	if (!fractol->img.img)
		ft_puterror(e_mlx_bad_init);
	fractol->img.addr = mlx_get_data_addr(
			fractol->img.img,
			&(fractol->img.bits_per_pixel),
			&(fractol->img.line_lenght),
			&(fractol->img.endian)
			);
	if (!fractol->img.addr)
		ft_puterror(e_mlx_bad_init);
	mlx_loop(fractol->mlx);
}
