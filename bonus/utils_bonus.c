#include "fractol_bonus.h"

double scaling_func(double num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min);
}

double  atodbl(char *str)
{
	double  number;
	double  fraction;
	double  power;
	int     sign;
	int     i;

	sign = 1;
	number = 0.0;
	fraction = 0.0;
	power = 1.0;
	i = 0;
	if (!str || !str)
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '.')
			break ;
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		power /= 10;
		fraction = fraction + (str[i] - '0') * power;
		i++;
	}
	return ((fraction + number) * sign);
}

int    exit_func(t_window *window)
{
	mlx_destroy_image(window->mlx, window->image.image);
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

void    pixel_put(int x, int y, t_image *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x *(img->bpp / 8));
	*(unsigned int *)(img->pixel + offset) = color;
}