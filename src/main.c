/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:18:26 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/05 08:36:21 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

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
int	main(void)  // int argc, char *argv[]
{
	// printf("Hello, fract-ol!\n");
	void	*mlx;
	void	*mlx_win;
	void	*mlx_2;
	void	*mlx_win_2;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 720, "42Docs. Hello, World!");
	mlx_2 = mlx_init();
	mlx_win_2 = mlx_new_window(mlx, 960, 720, "testing a second screen");
	mlx_loop(mlx);
	return (0);
}
 