/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:18:26 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/16 08:50:54 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2 && argv)
		ft_puterror(e_bad_input, &fractol);
	ft_fractol_init(&fractol);
	ft_start(argc, argv, &fractol);
	ft_mlx_init(&fractol);
	return (0);
}
