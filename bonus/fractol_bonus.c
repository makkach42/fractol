/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:38:13 by makkach           #+#    #+#             */
/*   Updated: 2025/03/02 11:48:32 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
}

void	error_func(void)
{
	ft_putstr("\nthe correct prototypes for this ");
	ft_putstr("program are the following\n\n\n");
	ft_putstr("     ./fractol mandelbrot\n     ./fractol multibrot\n");
	ft_putstr("     ./fractol julia <value> <value2>\n\n");
	ft_putstr("the values in the julia fractal ");
	ft_putstr("should be in the interval [-2, 2]\n");
	exit(1);
}

void	more_inits(t_window *window)
{
	window->x = 0;
	window->y = 0;
	window->zoom = 1.0;
	window->max_iter = 100;
	window->color = 0x020a13;
	window->image.pixel = mlx_get_data_addr(window->image.image,
			&window->image.bpp, &window->image.line_len, &window->image.endian);
}

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc == 2 && (!mandelbrot_check(argv[1]) || !multibrot_check(argv[1])))
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
			return (error_func(), 0);
		if (window.julia.imaginary > 2 || window.julia.imaginary < -2)
			return (error_func(), 0);
		window.name = "julia";
		window_mlx(&window);
	}
	else
		return (error_func(), 0);
}
