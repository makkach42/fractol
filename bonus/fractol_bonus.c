/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:38:13 by makkach           #+#    #+#             */
/*   Updated: 2025/02/26 10:01:12 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv) //range check //remove + - keys //change check for what to render its ass //error handle properly
{
	t_window	window;

	if (argc == 2)
	{
		if (mandelbrot_check(argv[1]) == 0)
			window.name = "mandelbrot";
		else if (multibrot_check(argv[1]) == 0)
			window.name = "multibrot";
		window_mlx(&window);
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
		window_mlx(&window);
	}
	return (0);
}
