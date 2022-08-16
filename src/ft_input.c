/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:20:17 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/16 08:50:35 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_start(int argc, char **argv, t_fractol *fractol)
{
	printf("%d %p %p", argc, argv, fractol);
	if (is_mandelbrot(argv[1]))
		ft_set_mandelbrot(fractol);
	else if (is_julia(argv[1]))
		printf("\nsim, é a julia!\n");
	else
		ft_puterror(e_invalid_fractol, fractol);
}
