NAME = fractol
INC = fractol.h

SRCS += fractol.c

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = gcc -Wall -Wextra -Werror

MLX_DIR = ./mlx/
MLX_LIB	= $(MLX_DIR)libmlx.a
MLX_LNK = -L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) $(MLX_LNK) -lm -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: %.c $(OBJS_DIR)
	$(CC) -I $(MLX_DIR) -c $< -o $@

$(OBJS_DIR):
	mkdir $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

bonus : all

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) re -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
