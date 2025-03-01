/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:40:52 by makkach           #+#    #+#             */
/*   Updated: 2025/03/01 12:02:37 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	handl_pixel(double x, double y, t_window *window)
{
	t_complex	z;
	t_complex	c;
	int			i;

	handl_pixel_inits(&i, &z);
	if (ft_strncmp(window->name, "mandelbrot", ft_strlen("mandelbrot")) == 0)
		c_set(&c, window, x, y);
	else if (ft_strncmp(window->name, "multibrot", ft_strlen("multibrot")) == 0)
		c_set(&c, window, x, y);
	else if (ft_strncmp(window->name, "julia", ft_strlen("julia")) == 0)
	{
		c_set(&c, window, x, y);
		z_set(&z, window, x, y);
	}
	while (++i < window->max_iter)
	{
		calculations(&z, &c, window);
		if ((z.imaginary * z.imaginary) + (z.real * z.real) > 4)
		{
			colors(i, x, y, window);
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
	mlx_put_image_to_window(window->mlx,
		window->win, window->image.image, 0, 0);
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
	window->x = 0;
	window->y = 0;
	window->zoom = 1.0;
	window->max_iter = 100;
	window->color = 0x020a13;
	window->image.pixel = mlx_get_data_addr(window->image.image,
			&window->image.bpp, &window->image.line_len, &window->image.endian);
	init_events(window);
}

int	get_color(int i, t_window *window)
{
	return (i * window->color);
}
