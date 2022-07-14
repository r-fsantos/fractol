/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:47:36 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/14 08:52:29 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	is_mandelbrot(char *str)
{
	return (!ft_strcmp(str, "mandelbrot"));
}

void	ft_set_mandelbrot(t_fractol *fractol)
{
	printf("%p\n", fractol);
}
