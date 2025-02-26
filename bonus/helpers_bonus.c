/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:27:05 by makkach           #+#    #+#             */
/*   Updated: 2025/02/26 10:27:10 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	julia_numbers_pars_helper(int i, int j, char **argv, int flag)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && (argv[i][j] == 32 || argv[i][j] == 9))
			j++;
		while (argv[i][j] != 32 && argv[i][j] != 9)
		{
			if (argv[i][j] && argv[i][j] >= '0' && argv[i][j] <= '9')
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
		i++;
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
	if (ft_strlen(window->name) == 10)
	{
		(*c).real = (scaling_func(x, -2, 2
					)) * window->zoom + window->x;
		(*c).imaginary = (scaling_func(y, 2, -2
					)) * window->zoom + window->y;
	}
	else if (ft_strlen(window->name) == 9)
	{
		(*c).real = (scaling_func(x, -2, 2
					)) * window->zoom + window->x;
		(*c).imaginary = (scaling_func(y, 2, -2
					)) * window->zoom + window->y;
	}
	else if (ft_strlen(window->name) == 5)
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

void	multibrot_calculations(t_complex *z, t_complex *c)
{
	double	tmpreal;
	double	r2;
	double	i2;

	r2 = (*z).real * (*z).real;
	i2 = (*z).imaginary * (*z).imaginary;
	tmpreal = r2 * (*z).real - 3 * (*z).real * i2 + (*c).real;
	(*z).imaginary = 3 * r2 * (*z
			).imaginary - i2 * (*z).imaginary + (*c).imaginary;
	(*z).real = tmpreal;
}
