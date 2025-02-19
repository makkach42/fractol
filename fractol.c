#include "fractol.h"

int func(int key, t_window *window)
{
    if (key == 53)
        exit(0);
    if (key == 123)
        window->x -= 10;
    if (key == 124)
        window->x += 10;
    if (key == 126)
        window->y -= 10;
    if (key == 125)
        window->y += 10;
    return (0);
}

int main()
{
    t_window *window;

    window = malloc(sizeof(t_window));
    window->mlx = mlx_init();
    window->win = mlx_new_window(window->mlx, 800, 600, "window");
    window->x = 200;
    int k = 200;
    int i = 0;
    int j = 600;
    window->y = 200;

    while (window->y < 400)
    {
        window->x = k - i;
        while (window->x < j)
        {
            mlx_pixel_put(window->mlx, window->win, window->x, window->y, 0xFF0000);
            window->x++;
        }
        window->y++;
        i--;
        j--;
    }
    mlx_key_hook(window->win, func, window);

    mlx_loop(window->mlx);
}