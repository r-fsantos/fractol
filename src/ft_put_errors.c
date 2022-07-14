/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:27:19 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/13 22:46:01 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	ft_default_msg(int fd);
static void	ft_put_bad_input_fd(int fd);
static void	ft_put_invalid_fractol_fd(int fd);

void	ft_puterror(int e_error_code)
{
	ft_putendl_fd("ERROR!", e_fd_std_out);
	if (e_error_code == e_bad_input)
		ft_put_bad_input_fd(e_fd_std_out);
	if (e_error_code == e_invalid_fractol)
		ft_put_invalid_fractol_fd(e_fd_std_out);
	ft_default_msg(e_fd_std_out);
	exit(-1);
}

static void	ft_put_bad_input_fd(int fd)
{
	ft_putendl_fd("Entradas incompatíveis!", fd);
}

static void	ft_put_invalid_fractol_fd(int fd)
{
	ft_putendl_fd("Fractol não suportado e/ou entrada inválida!", fd);
}

static void	ft_default_msg(int fd)
{
	ft_putendl_fd("Favor referir-se ao README! :)", fd);
}
