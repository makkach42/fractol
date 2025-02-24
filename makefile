NAME2 = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra
MLX_DIR = minilibx_opengl
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
SRCS = bonus/fractol_bonus.c bonus/pars_bonus.c bonus/utils_bonus.c bonus/mandelbrot_bonus.c bonus/events_bonus.c
OBJS = $(SRCS:.c=.o)

all: $(NAME2)

$(NAME2): $(OBJS) bonus/fractol_bonus.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME2) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME2)

re: fclean all
