/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:27:19 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/14 10:37:53 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_puterror(int e_error_code)
{
	ft_putendl_fd("ERROR!", e_fd_std_out);
	if (e_error_code == e_bad_input)
		ft_putendl_fd(BAD_INPUT, e_fd_std_out);
	if (e_error_code == e_invalid_fractol)
		ft_putendl_fd(UNSUPORTED_FRACTOL, e_fd_std_out);
	if (e_bad_input == e_mlx_bad_init)
		ft_putendl_fd(MLX_BAD_INIT, e_fd_std_out);
	ft_putendl_fd(DEFAULT_HELP_MESSAGE, e_fd_std_out);
	exit(-1);
}
