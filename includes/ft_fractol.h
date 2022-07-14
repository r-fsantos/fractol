/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:23:10 by rfelicio          #+#    #+#             */
/*   Updated: 2022/07/14 08:51:59 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

// Use printf only
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <errno.h>
# include "libft.h"

// Defines
# define MANDELBROT "mandelbrot"
# define JULIA "julia"

// Enums
enum e_error_msg_codes
{
	e_bad_input = 0,
	e_invalid_fractol = 1
};

enum e_fd
{
	e_fd_std_out = 1
};

enum e_fractals
{
	e_mandelbrot = 0,
	e_julia = 1
};

// Structs
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	char	*name;
	t_data	img;
	void	*mlx;
	void	*mlx_win;
}	t_fractol;

// Error handlers
void	ft_puterror(int e_error_code);

// Fractol logic
void	ft_fractol_init(t_fractol *fractol);
void	ft_start(int argc, char **argv, t_fractol *fractol);

// Mandelbrot
int		is_mandelbrot(char *str);
void	ft_set_mandelbrot(t_fractol *fractol);

// Julia
int		is_julia(char *str);

#endif
