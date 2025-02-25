#include "fractol_bonus.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void handl_pixel(double x, double y, t_window *window)
{
	t_complex   z;
	t_complex   c;
	double      tmpreal;
	int         i;
	int         color;
	
	i = 0;
	z.real = 0;
	z.imaginary = 0;
	if (ft_strlen(window->name) == 10)
	{
		c.real = (scaling_func(x, -2, 2, 0, WIDTH)) * window->zoom + window->x;
		c.imaginary = (scaling_func(y, 2, -2, 0, HEIGHT)) * window->zoom + window->y;
	}
	else if (ft_strlen(window->name) == 9)
	{
		c.real = (scaling_func(x, -2.5, 1, 0, WIDTH)) * window->zoom + window->x;
		c.imaginary = (scaling_func(y, 1, -1, 0, HEIGHT)) * window->zoom + window->y;
	}
	else if (ft_strlen(window->name) == 5)
	{
		c.real = window->julia.real;
		c.imaginary = window->julia.imaginary;
		z.real = (scaling_func(x, -2, 2, 0, WIDTH)) * window->zoom + window->x;
		z.imaginary = (scaling_func(y, 2, -2, 0, HEIGHT)) * window->zoom + window->y;
	}
	while (i < window->max_iter)
	{
		if (ft_strlen(window->name) == 9)
		{
			double r2 = z.real * z.real;
			double i2 = z.imaginary * z.imaginary;
			tmpreal = r2 * z.real - 3 * z.real * i2 + c.real;
			z.imaginary = 3 * r2 * z.imaginary - i2 * z.imaginary + c.imaginary;
			z.real = tmpreal;
		}
		else
		{
			tmpreal = (z.real * z.real) - (z.imaginary * z.imaginary) + c.real;
			z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
			z.real = tmpreal;
		}
		
		if ((z.imaginary * z.imaginary) + (z.real * z.real) > 4)
		{
			color = scaling_func(i, window->color, 0xFFFFFF, 0, 799);
			pixel_put(x, y, &window->image, color);
			return;
		}
		i++;
	}
	pixel_put(x, y, &window->image, 0x000000);
}
void fractal_render(t_window *window)
{
	int x;
	int y;

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
	mlx_put_image_to_window(window->mlx, window->win, window->image.image, 0, 0);
}

void    window_init(t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		exit(1);
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, window->name);
	if (!window->win)
	{
		free(window->mlx);
		exit(1);
	}
	window->image.image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!window->image.image)
	{
		mlx_destroy_window(window->mlx, window->win);
		free(window->mlx);
		exit(1);
	}
	window->x = 0;
	window->y = 0;
	window->zoom = 1.0;
	window->max_iter = 100;
	window->color = 0x000000;
	window->image.pixel = mlx_get_data_addr(window->image.image, &window->image.bpp, &window->image.line_len, &window->image.endian);
	init_events(window);
}
