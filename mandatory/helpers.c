/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:37:17 by makkach           #+#    #+#             */
/*   Updated: 2025/02/25 16:01:54 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	z_set(t_window *window, t_complex *z, int x, int y)
{
	if (ft_strlen(window->name) == 10)
	{
		(*z).real = 0;
		(*z).imaginary = 0;
	}
	else if (ft_strlen(window->name) == 5)
	{
		(*z).real = (scaling_func(x, -2, 2)) * window->zoom;
		(*z).imaginary = (scaling_func(y, 2, -2)) * window->zoom;
	}
}

void	mandelbrot_helper(int x, int y, int i, t_window *window)
{
	int	color;

	color = scaling_func(i, 0x000000, 0xFFFFFF);
	pixel_put(x, y, &window->image, color);
}
