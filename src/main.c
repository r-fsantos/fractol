/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:18:26 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/13 21:46:59 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

/*
** TODO: Parse inputs
**		- input validation: 
**			./fractol fractal-name 
**				if fractal-name=='julia';
**				then parse (+/-xx.x +/- jyy.y) as well
**
** TODO: Fractal logic
**		- mandelbroot
**		- julia
**		- burning ship
**
** TODO: mlx_setup and loops
**		- do not forget to destroy images and free mem for linux.
*/
int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2 && argv)
		ft_puterror(e_bad_input);
	ft_fractol_init(&fractol);
	ft_start(argc, argv, &fractol);
	ft_mlx_init(&fractol);
	return (0);
}
