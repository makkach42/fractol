NAME2 = fractol_bonus
NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = mandatory/fractol.c mandatory/pars.c mandatory/utils.c mandatory/mandelbrot.c mandatory/events.c mandatory/helpers.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = bonus/fractol_bonus.c bonus/pars_bonus.c bonus/utils_bonus.c bonus/mandelbrot_bonus.c bonus/events_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) mandatory/fractol.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

bonus: $(NAME2)
$(NAME2): $(OBJS_BONUS) bonus/fractol_bonus.h
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME2) $(MLX_FLAGS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all
