/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:37 by makkach           #+#    #+#             */
/*   Updated: 2025/02/26 11:20:56 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	error_func()
{
	write(2, "\nthe correct prototypes for this program are the following\n\n\n     ./fractol mandelbrot\n     ./fractol julia <value> <value2>\n\nthe values in the julia fractal should be in the interval [-2, 2]\n", 192);
}

int	main(int argc, char **argv)//error handle properly
{
	t_window	window;

	if (argc == 2 && mandelbrot_check(argv[1]) == 0)
	{
		window.name = "mandelbrot";
		window_init(&window);
		fractal_render(&window);
		mlx_loop((&window)->mlx);
	}
	else if (argc == 4 && julia_check(argv) == 1)
	{
		window.julia.real = atodbl(argv[2]);
		window.julia.imaginary = atodbl(argv[3]);
		if (window.julia.real > 2 || window.julia.real < -2)
			return (error_func(), 1);
		if (window.julia.imaginary > 2 || window.julia.imaginary < -2)
			return (error_func(), 1);
		window.name = "julia";
		window_init(&window);
		fractal_render(&window);
		mlx_loop((&window)->mlx);
	}
	else
		return (error_func(), 1);
}
