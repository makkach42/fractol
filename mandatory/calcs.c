/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:51:38 by makkach           #+#    #+#             */
/*   Updated: 2025/03/02 19:46:42 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	handl_pixel(double x, double y, t_window *window)
{
	t_complex	z;
	t_complex	c;
	int			i;

	if (ft_strncmp(window->name, "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		z_set(window, &z, x, y);
		c_set(window, &c, x, y);
	}
	else if (ft_strncmp(window->name, "julia", ft_strlen("julia")) == 0)
	{
		c_set(window, &c, x, y);
		z_set(window, &z, x, y);
	}
	i = -1;
	while (++i < window->max_iter)
	{
		calculation(&z, &c);
		if ((z.imaginary * z.imaginary) + (z.real * z.real) > 4)
		{
			coloring(x, y, i, window);
			return ;
		}
	}
	pixel_put(x, y, &window->image, 0x000000);
}

void	fractal_render(t_window *window)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handl_pixel(x, y, window);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx, window->win,
		window->image.image, 0, 0);
}

void	window_init(t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		exit(1);
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, window->name);
	if (!window->win)
		exit(1);
	window->image.image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!window->image.image)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit(1);
	}
	window->zoom = 1.0;
	window->max_iter = 100;
	window->image.pixel = mlx_get_data_addr(window->image.image,
			&window->image.bpp, &window->image.line_len, &window->image.endian);
	init_events(window);
}
