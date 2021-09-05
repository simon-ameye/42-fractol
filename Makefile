# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sameye <sameye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 14:02:57 by sameye            #+#    #+#              #
#    Updated: 2021/09/03 19:10:47 by sameye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INC = fractol.h

SRCS += fractol.c
SRCS += window.c
SRCS += fractol_utils.c

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = gcc -Wall -Wextra -Werror

MLX_DIR = ./mlx/
MLX_LIB	= $(MLX_DIR)libmlx.a
MLX_LNK = -L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit

LFT_DIR = ./libft/
LFT_LIB = $(LFT_DIR)libft.a
LFT_LNK = -L $(LFT_DIR) -l ft

all: $(NAME)

$(NAME) : $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) $(MLX_LNK) $(LFT_LNK) -lm -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: %.c $(OBJS_DIR)
	$(CC) -I $(MLX_DIR) -I $(LFT_DIR) -c $< -o $@

$(OBJS_DIR):
	mkdir $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LFT_LIB):
	$(MAKE) -C $(LFT_DIR)

bonus : all

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) re -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
