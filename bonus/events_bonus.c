/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:38:06 by makkach           #+#    #+#             */
/*   Updated: 2025/02/26 10:59:19 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_func(int key, t_window *window)
{
	if (key == 53)
		exit_func(window);
	if (key == 123)
		window->x -= (0.5 * window->zoom);
	if (key == 124)
		window->x += (0.5 * window->zoom);
	if (key == 125)
		window->y -= (0.5 * window->zoom);
	if (key == 126)
		window->y += (0.5 * window->zoom);
	if (key == 83)
		window->color = 0x000000;
	if (key == 84)
		window->color = 0xC0C0C0;
	if (key == 85)
		window->color = 0xFF0000;
	if (key == 86)
		window->color = 0x800000;
	fractal_render(window);
	return (0);
}

int	mouse_func(int button, int x, int y, t_window *window)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	if (!window)
		return (0);
	mouse_x = (scaling_func(x, -2, 2)) * window->zoom + window->x;
	mouse_y = (scaling_func(y, 2, -2)) * window->zoom + window->y;
	if (button == 4)
		zoom_factor = 2.0;
	else if (button == 5)
		zoom_factor = 0.5;
	else
		return (0);
	window->zoom *= zoom_factor;
	window->x = mouse_x - (scaling_func(x, -2, 2)) * window->zoom;
	window->y = mouse_y - (scaling_func(y, 2, -2)) * window->zoom;
	fractal_render(window);
	return (0);
}

void	init_events(t_window *window)
{
	mlx_key_hook(window->win, key_func, window);
	mlx_mouse_hook(window->win, mouse_func, window);
	mlx_hook(window->win, 17, 0, exit_func, window);
}
