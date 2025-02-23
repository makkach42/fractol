#include "fractol.h"

double scaling_func(double num, double new_min, double new_max, double old_min, double old_max)
{
    return ((new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min);
}

void    pixel_put(int x, int y, t_image *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x *(img->bpp / 8));
    *(unsigned int *)(img->pixel + offset) = color;
}
void    handl_pixel(double x, double y, t_window *window)
{
    t_complex   z;
    t_complex   c;
    double      tmpreal;
    int         i;
    int         color;

    z.real = 0;
    z.imaginary = 0;
    c.real = (scaling_func(x, -2, 2, 0, WIDTH)) * window->zoom;
    c.imaginary = (scaling_func(y, 2, -2, 0, HEIGHT)) * window->zoom;
    tmpreal = 0;
    i = 0;
    while (i < window->max_iter)
    {
        tmpreal = (z.real * z.real) - (z.imaginary * z.imaginary) + c.real + window->x;
        z.imaginary = 2 * z.real * z.imaginary + c.imaginary + window->y;
        z.real = tmpreal;
        if ((z.imaginary * z.imaginary) + (z.real * z.real) > 4)
        {
            color = scaling_func(i, 0x000000, 0xFFFFFF, 0, window->max_iter);
            pixel_put(x, y, &window->image, color);
            return ;
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
void    exit_func(t_window *window)
{
    mlx_destroy_image(window->mlx, window->image.image);
    mlx_destroy_window(window->mlx, window->win);
    free(window->mlx);
    exit(0);
}

int    key_func(int key, t_window *window)
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
    if (key == 69)
        window->max_iter += 10;
    if (key == 78)
        window->max_iter -= 10;
    fractal_render(window);
    return (0);
}

int     mouse_func(int button, int x, int y, t_window *window)
{
    if (!window)
        return (0);
    
    if (button == 5)
        window->zoom *= 2.0;
    if (button == 4)
        window->zoom /= 2.0;
    fractal_render(window);
    return (0);
}
void    init_events(t_window *window)
{
    mlx_key_hook(window->win, key_func, window);
    mlx_mouse_hook(window->win, mouse_func, window);
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
    window->image.pixel = mlx_get_data_addr(window->image.image, &window->image.bpp, &window->image.line_len, &window->image.endian);
    init_events(window);
}
int main()
{
    t_window window;

    window_init(&window);
    fractal_render(&window);
    mlx_loop((&window)->mlx);
    return (0);
}
