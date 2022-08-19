/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:20:17 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/19 10:21:52 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_start(int argc, char **argv, t_fractol *fractol)
{
	if (is_mandelbrot(argv[1]))
		ft_set_mandelbrot(fractol);
	else if (is_julia(argc, argv))
		ft_set_julia(argv, fractol);
	else
		ft_puterror(e_invalid_fractol, fractol);
}
