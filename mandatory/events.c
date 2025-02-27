/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:51 by makkach           #+#    #+#             */
/*   Updated: 2025/02/27 11:53:57 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_func(int key, t_window *window)
{
	if (key == 53)
		exit_func(window);
	fractal_render(window);
	return (0);
}

int	mouse_func(int button, int x, int y, t_window *window)
{
	double	zoom_factor;

	(void)x;
	(void)y;
	if (!window)
		return (0);
	if (button == 4)
		zoom_factor = 2.0;
	else if (button == 5)
		zoom_factor = 0.5;
	else
		return (0);
	window->zoom *= zoom_factor;
	fractal_render(window);
	return (0);
}

void	init_events(t_window *window)
{
	mlx_key_hook(window->win, key_func, window);
	mlx_mouse_hook(window->win, mouse_func, window);
	mlx_hook(window->win, 17, 0, exit_func, window);
}

void	calculation(t_complex *z, t_complex *c)
{
	double	tmpreal;

	tmpreal = ((*z).real * (*z).real) - (
			(*z).imaginary * (*z).imaginary) + (*c).real;
	(*z).imaginary = 2 * (*z).real * (*z).imaginary + (*c).imaginary;
	(*z).real = tmpreal;
}

void	c_set(t_window *window, t_complex *c, int x, int y)
{
	if (ft_strncmp(window->name, "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		(*c).real = (scaling_func(x, -2, 2)) * window->zoom;
		(*c).imaginary = (scaling_func(y, 2, -2)) * window->zoom;
	}
	else if (ft_strncmp(window->name, "julia", ft_strlen("julia")) == 0)
	{
		(*c).real = window->julia.real;
		(*c).imaginary = window->julia.imaginary;
	}
}
