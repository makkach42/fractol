#include "fractol.h"

int    key_func(int key, t_window *window)
{
    if (key == 53)
        exit_func(window);
    if (key == 69)
        window->max_iter += 10;
    if (key == 78)
        window->max_iter -= 10;
    fractal_render(window);
    return (0);
}

int mouse_func(int button, int x, int y, t_window *window)
{
    double  zoom_factor;
    
    (void)x;
    (void)y;
    if (!window)
        return (0);
    if (button == 4)
        zoom_factor = 2.0;
    else if (button == 5)
        zoom_factor = 0.5;
    else
        return (0);
    window->zoom *= zoom_factor;
    fractal_render(window);
    return (0);
}
void    init_events(t_window *window)
{
    mlx_key_hook(window->win, key_func, window);
    mlx_mouse_hook(window->win, mouse_func, window);
    mlx_hook(window->win, 17, 0, exit_func, window);
}