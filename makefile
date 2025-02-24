NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra
MLX_DIR = minilibx_opengl
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
SRCS = fractol.c pars.c utils.c mandelbrot.c events.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) fractol.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
