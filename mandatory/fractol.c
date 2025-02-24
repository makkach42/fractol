#include "fractol.h"

int main(int argc, char **argv) //range check //remove + - keys
{
    if (argc == 2 && mandelbrot_check(argv[1]) == 0)
    {
        t_window window;

        window.name = "mandelbrot";
        window_init(&window);
        fractal_render(&window);
        mlx_loop((&window)->mlx);
    }
    else if (argc == 4 && julia_check(argv) == 1)
    {
        t_window window;

        window.julia.real = atodbl(argv[2]);
        window.julia.imaginary = atodbl(argv[3]);
        window.name = "julia";
        window_init(&window);
        fractal_render(&window);
        mlx_loop((&window)->mlx);
    }
    return (0);
}
