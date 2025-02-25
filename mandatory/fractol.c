/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:37 by makkach           #+#    #+#             */
/*   Updated: 2025/02/25 15:45:05 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv) //range check //remove + - keys //change check for what to render its ass //error handle properly
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
			return (0);
		if (window.julia.imaginary > 2 || window.julia.imaginary < -2)
			return (0);
		window.name = "julia";
		window_init(&window);
		fractal_render(&window);
		mlx_loop((&window)->mlx);
	}
	return (0);
}
