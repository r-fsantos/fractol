/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:27:19 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/20 08:40:12 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_puterror(int e_error_code, t_fractol *fractol)
{
	ft_putendl_fd("ERROR!", e_fd_std_out);
	if (e_error_code == e_bad_input)
		ft_putendl_fd(BAD_INPUT, e_fd_std_out);
	if (e_error_code == e_invalid_fractol)
		ft_putendl_fd(UNSUPORTED_FRACTOL, e_fd_std_out);
	if (e_bad_input == e_mlx_bad_init)
		ft_putendl_fd(MLX_BAD_INIT, e_fd_std_out);
	ft_put_help_msg(e_fd_std_out);
	ft_should_close(fractol);
	exit(-1);
}

void	ft_put_help_msg(int fd)
{
	ft_putendl_fd("", fd);
	ft_putendl_fd("Padrão de funcionamento do programa", fd);
	ft_putendl_fd("./fractol mandelbrot", fd);
	ft_putendl_fd("./fractol julia X.XXX X.XXX", fd);
	ft_putendl_fd("./fractol julia +X.XXX +X.XXX", fd);
	ft_putendl_fd("./fractol julia -X.XXX -X.XXX", fd);
	ft_putendl_fd("", fd);
	ft_putendl_fd("Exemplos para o julia. O uso de sinal é facultativo.", fd);
	ft_putendl_fd("./fractol julia +0.4 +0.6", fd);
	ft_putendl_fd("./fractol julia -0.4 -0.6", fd);
	ft_putendl_fd("./fractol julia 0.0 1.0", fd);
	ft_putendl_fd("./fractol julia 0.285 0.0", fd);
	ft_putendl_fd("./fractol julia -0.74 0.12", fd);
}
