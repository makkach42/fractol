#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_window
{
    void    *mlx;
    void    *win;
    int     x;
    int     y;
}   t_window;

int julia_check(char **argv);
int mandelbrot_check(char *argv);

#endif