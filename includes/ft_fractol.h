/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:23:10 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/16 08:34:29 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

// Use printf only
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <errno.h>
# include "../libs/libft/include/libft.h"

// Defines
# define MANDELBROT "mandelbrot"
# define JULIA "julia"

# define BAD_INPUT "Entradas incompatíveis!"
# define UNSUPORTED_FRACTOL "Fractol não suportado e/ou entrada inválida!"
# define DEFAULT_HELP_MESSAGE "Favor referir-se ao README! :)"
# define MLX_BAD_INIT "Erro de inicialização da minilibx"
# define WIN_WIDTH 700
# define WIN_HEIGHT 700
# define WIN_SIDE 700
# define MIN_AXIS -2.0
# define MAX_AXIS 2.0
# define MAX_ITERATIONS 80

# if defined(__linux__) && __linux__
#  define LEFT_ARROW_KEY 65361
#  define RIGHT_ARROW_KEY 65362
#  define UP_ARROW_KEY 65363
#  define DOWN_ARROW_KEY 65364
#  define ESC_KEY 65307
# else
#  define LEFT_ARROW_KEY 123
#  define RIGHT_ARROW_KEY 124
#  define UP_ARROW_KEY 126
#  define DOWN_ARROW_KEY 125
#  define ESC_KEY 53
# endif


// Enums
enum e_error_msg_codes
{
	e_bad_input = 0,
	e_invalid_fractol = 1,
	e_mlx_bad_init = 2
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

enum e_keycodes
{
	e_left = LEFT_ARROW_KEY,
	e_right = RIGHT_ARROW_KEY,
	e_down = DOWN_ARROW_KEY,
	e_up = UP_ARROW_KEY,
	e_zooming_in = 4,
	e_zooming_out = 5,
	e_esc = ESC_KEY
};

// Structs
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	step;
}	t_data;

typedef struct s_fractol
{
	char	*name;
	int		type;
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
}	t_fractol;

// Error handlers
void	ft_puterror(int e_error_code, t_fractol *fractol);

// Fractol logic
void	ft_fractol_init(t_fractol *fractol);
void	ft_start(int argc, char **argv, t_fractol *fractol);
void	ft_calculate_fractal(t_data *img, int type);

// Mandelbrot
int		is_mandelbrot(char *str);
void	ft_set_mandelbrot(t_fractol *fractol);
int		ft_mandelbrot(double x, double y);

// Julia
int		is_julia(char *str);

// Mlx
void	ft_mlx_init(t_fractol *fractol);
int		ft_should_close(t_fractol *fractol);
void	ft_panning(int key, t_data *img);
int		it_pressed_any_arrow_key(int key);

// Mlx hooks
void	ft_setup_hooks(t_fractol *fractol);
int		ft_on_pressing_key(int key, t_fractol *fractol);
int		ft_on_zooming(int key, int x, int y, t_fractol *fractol);
void	ft_following_mouse(t_data *img, int x, int y);


// Colors
void	ft_setup_colors(double x, double y, int iterations, t_data *img);

#endif
