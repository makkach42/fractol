#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include "minilibx_opengl/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define ITER_MAX 100
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
    t_complex   *coords;
    t_image     image;
}   t_window;


int julia_check(char **argv);
int mandelbrot_check(char *argv);

#endif