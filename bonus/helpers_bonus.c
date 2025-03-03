/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:27:05 by makkach           #+#    #+#             */
/*   Updated: 2025/03/03 12:31:22 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	julia_numbers_pars_helper(int i, int j, char **argv, int flag)
{
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j] && (argv[i][j] == 32 || argv[i][j] == 9))
			j++;
		while (argv[i][j] != 32 && argv[i][j] != 9)
		{
			if (argv[i][j] && ((argv[i][j] == '-' || argv[i][j]
				== '+') || (argv[i][j] >= '0' && argv[i][j] <= '9')))
				j++;
			else if (argv[i][j] && argv[i][j] == '.' && flag == 1)
			{
				j++;
				flag = 0;
			}
			else
				break ;
		}
		while (argv[i][j] && (argv[i][j] == 32 || argv[i][j] == 9))
			j++;
		if (argv[i][j] != '\0')
			break ;
		flag = 1;
	}
	return (i);
}

void	window_mlx(t_window *window)
{
	window_init(window);
	fractal_render(window);
	mlx_loop((window)->mlx);
}

void	c_set(t_complex *c, t_window *window, int x, int y)
{
	if (ft_strncmp(window->name, "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		(*c).real = (scaling_func(x, -2, 2
					)) * window->zoom + window->x;
		(*c).imaginary = (scaling_func(y, 2, -2
					)) * window->zoom + window->y;
	}
	else if (ft_strncmp(window->name, "tricorn", ft_strlen("tricorn")) == 0)
	{
		(*c).real = (scaling_func(x, -2, 2
					)) * window->zoom + window->x;
		(*c).imaginary = (scaling_func(y, 2, -2
					)) * window->zoom + window->y;
	}
	else if (ft_strncmp(window->name, "julia", ft_strlen("julia")) == 0)
	{
		(*c).real = window->julia.real;
		(*c).imaginary = window->julia.imaginary;
	}
}

void	z_set(t_complex *z, t_window *window, int x, int y)
{
	(*z).real = (scaling_func(x, -2, 2
				)) * window->zoom + window->x;
	(*z).imaginary = (scaling_func(y, 2, -2
				)) * window->zoom + window->y;
}

void	tricorn_calculations(t_complex *z, t_complex *c)
{
	double	tmpreal;
	double	r2;
	double	i2;

	r2 = (*z).real * (*z).real;
	i2 = (*z).imaginary * (*z).imaginary;
	tmpreal = r2 - i2 + (*c).real;
	(*z).imaginary = -2 * (*z).real * (*z).imaginary + (*c).imaginary;
	(*z).real = tmpreal;
}
