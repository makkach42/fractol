/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:43:20 by makkach           #+#    #+#             */
/*   Updated: 2025/03/02 19:45:54 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
	void		*mlx;
	void		*win;
	double		zoom;
	int			max_iter;
	char		*name;
	t_complex	julia;
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
void	init_events(t_window *window);
int		ft_strlen(char *str);
void	calculation(t_complex *z, t_complex *c);
void	c_set(t_window *window, t_complex *c, int x, int y);
void	z_set(t_window *window, t_complex *z, int x, int y);
void	coloring(int x, int y, int i, t_window *window);
int		ft_strncmp(char *str1, char *str2, size_t n);

#endif