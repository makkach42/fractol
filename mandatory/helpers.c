/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:37:17 by makkach           #+#    #+#             */
/*   Updated: 2025/02/27 18:02:46 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	z_set(t_window *window, t_complex *z, int x, int y)
{
	if (ft_strncmp(window->name, "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		(*z).real = 0;
		(*z).imaginary = 0;
	}
	else if (ft_strncmp(window->name, "julia", ft_strlen("julia")) == 0)
	{
		(*z).real = (scaling_func(x, -2, 2)) * window->zoom;
		(*z).imaginary = (scaling_func(y, 2, -2)) * window->zoom;
	}
}

int	get_color(int i)
{
	return (i * 0x020a13);
}

void	mandelbrot_helper(int x, int y, int i, t_window *window)
{
	int	color;

	color = get_color(i);
	pixel_put(x, y, &window->image, color);
}

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t			i;
	unsigned char	*str11;
	unsigned char	*str22;

	i = 0;
	str11 = (unsigned char *)str1;
	str22 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str11[i] == '\0' || str22[i] == '\0')
		{
			return ((str11[i] - str22[i]));
		}
		if (str11[i] != str22[i])
			return (str11[i] - str22[i]);
		i++;
	}
	return (0);
}
