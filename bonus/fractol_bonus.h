#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
typedef struct s_image
{
	void    *image;
	char    *pixel;
	int     bpp;
	int     line_len;
	int     endian;
}   t_image;

typedef struct s_complex
{
	double real;
	double imaginary;
}   t_complex;

typedef struct s_window
{
	double      x;
	double      y;
	void        *mlx;
	void        *win;
	double      zoom;
	int         max_iter;
	int         color;
	char        *name;
	t_complex   julia;
	t_complex   *coords;
	t_image     image;
}   t_window;


int     julia_check(char **argv);
int     mandelbrot_check(char *argv);
double  scaling_func(double num, double new_min, double new_max, double old_min, double old_max);
double  atodbl(char *str);
int     exit_func(t_window *window);
void    pixel_put(int x, int y, t_image *img, int color);
void    window_init(t_window *window);
void    fractal_render(t_window *window);
int     key_func(int key, t_window *window);
int     mouse_func(int button, int x, int y, t_window *window);
void    init_events(t_window *window);
int		multibrot_check(char *argv);

#endif