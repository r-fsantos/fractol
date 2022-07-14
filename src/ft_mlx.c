/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:40:59 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/14 10:41:05 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_mlx_init(t_fractol *fractol)
{
	printf("fractol name: %s\n", fractol->name);
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		ft_puterror(e_mlx_bad_init);
}
