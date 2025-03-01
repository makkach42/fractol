/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:38:56 by makkach           #+#    #+#             */
/*   Updated: 2025/03/01 11:39:30 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_image
{
	void	*image;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_window
{
	double		x;
	double		y;
	void		*mlx;
	void		*win;
	double		zoom;
	int			max_iter;
	int			color;
	char		*name;
	t_complex	julia;
	t_complex	*coords;
	t_image		image;
}	t_window;

int		julia_check(char **argv);
int		mandelbrot_check(char *argv);
double	scaling_func(double num, double new_min, double new_max);
double	atodbl(char *str);
int		exit_func(t_window *window);
void	pixel_put(int x, int y, t_image *img, int color);
void	window_init(t_window *window);
void	fractal_render(t_window *window);
int		key_func(int key, t_window *window);
int		mouse_func(int button, int x, int y, t_window *window);
void	init_events(t_window *window);
int		multibrot_check(char *argv);
int		julia_numbers_pars_helper(int i, int j, char **argv, int flag);
void	window_mlx(t_window *window);
void	c_set(t_complex *c, t_window *window, int x, int y);
void	z_set(t_complex *z, t_window *window, int x, int y);
void	multibrot_calculations(t_complex *z, t_complex *c);
void	regular_calculations(t_complex *z, t_complex *c);
void	calculations(t_complex *z, t_complex *c, t_window *window);
void	colors(int i, int x, int y, t_window *window);
int		ft_strlen(char *str);
void	handl_pixel_inits(int *i, t_complex *z);
int		ft_strncmp(char *str1, char *str2, size_t n);
int		get_color(int i, t_window *window);

#endif