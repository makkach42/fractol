#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800
typedef struct s_image
{
    void    *image;
    char    *pixel;
    int     bpp;
    int     line_len;
}   t_image;

typedef struct s_window
{
    void    *mlx;
    void    *win;
    t_image *image;
}   t_window;

typedef struct s_complex
{
    double real;
    double imaginary;
}   t_complex;

int julia_check(char **argv);
int mandelbrot_check(char *argv);

#endif