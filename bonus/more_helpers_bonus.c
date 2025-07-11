/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_helpers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:26:57 by makkach           #+#    #+#             */
/*   Updated: 2025/03/02 20:10:09 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	regular_calculations(t_complex *z, t_complex *c)
{
	double	tmpreal;

	tmpreal = ((*z).real * (*z).real) - ((
				*z).imaginary * (*z).imaginary) + (*c).real;
	(*z).imaginary = 2 * (*z).real * (*z).imaginary + (*c).imaginary;
	(*z).real = tmpreal;
}

void	calculations(t_complex *z, t_complex *c, t_window *window)
{
	if (ft_strncmp(window->name, "tricorn", ft_strlen("tricorn")) == 0)
		tricorn_calculations(z, c);
	else
		regular_calculations(z, c);
}

void	colors(int i, int x, int y, t_window *window)
{
	double	color;

	color = get_color(i, window);
	pixel_put(x, y, &window->image, color);
}

void	handl_pixel_inits(int *i, t_complex *z)
{
	(*i) = -1;
	(*z).real = 0;
	(*z).imaginary = 0;
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
