/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:37 by makkach           #+#    #+#             */
/*   Updated: 2025/03/02 19:41:09 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
}

static void	error_func(void)
{
	ft_putstr("\nthe correct prototypes for this ");
	ft_putstr("program are the following\n\n\n");
	ft_putstr("     ./fractol mandelbrot\n     ./fractol multibrot\n");
	ft_putstr("     ./fractol julia <value> <value2>\n\n");
	ft_putstr("the values in the julia fractal ");
	ft_putstr("should be in the interval [-2, 2]\n");
	exit(1);
}

int	main(int argc, char **argv)
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
