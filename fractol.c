#include "fractol.h"

// int func(int key)
// {
//     if (key == 53)
//         exit(0);
//     return (0);
// }

    // t_window *window;

    // window = malloc(sizeof(t_window));
    // window->mlx = mlx_init();
    // window->width = 800;
    // window->hight = 600;
    // window->win = mlx_new_window(window->mlx, window->width, window->hight, "window");
    // window->x = 200;
    // window->y = 200;
    // int k = 600;
    // int l = 400;
    // int m = 200;

    // while (window->y < l)
    // {
    //     window->x = m;
    //     while (window->x < k)
    //     {
    //         mlx_pixel_put(window->mlx, window->win, window->x, window->y, 0xFFF0000);
    //         window->x++;
    //     }
    //     m++;
    //     k--;
    //     window->y++;
    // }
    // mlx_key_hook(window->win, func, window);

    // mlx_loop(window->mlx);
double scaling_func(double num, double new_min, double new_max, double old_min, double old_max)
{
    return ((new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min);
}
void    window_init(t_window *window)
{
    window->mlx = mlx_init();
    if (!window->mlx)
    {
        exit(1);
    }
    window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "fractal");
    if (!window->win)
    {
        free(window->mlx);
        exit(1);
    }
    window->image->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
    if (!window->image->image)
    {
        mlx_destroy_window(window->mlx, window->win);
        free(window->mlx);
        exit(1);
    }
    window->image->pixel = mlx_get_data_addr(window->image->image, &window->image->bpp, &window->image->line_len, 0);
    //hooks;
}
int main()
{
//     t_complex z;
//     t_complex c;

//     z.real = 0;
//     z.imaginary = 0;

//     c.real = 0;
//     c.imaginary = 0;
//     int i = 0;
//     double tmpreal;
//     while (i < 10)
//     {
//         tmpreal = (z.real * z.real) - (z.imaginary * z.imaginary);
//         z.imaginary = 2 * z.real * z.imaginary;
//         z.real = tmpreal;
//         z.real += c.real;
//         z.imaginary += c.imaginary;
//         printf("iteration %d, z.real = %f, z.imaginary = %f\n", i, z.real,z.imaginary);
//         i++;
//     }

//  init

// render

//  mlx_loop
    int i = 0;
    while (i < 8)
    {
        printf("%d, %f\n", i, scaling_func(i, -2, 2, 0, 799));
        i++;
    }

    return (0);
}
