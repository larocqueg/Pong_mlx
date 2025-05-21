# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 11:00:04 by gde-la-r          #+#    #+#              #
#    Updated: 2025/05/21 11:00:21 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pong
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
LDFLAGS = -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
INCLUDES = ./includes
LIBFT_DIR = ./libs/libft
MLX_DIR = ./libs/mlx
MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
SRCS_DIR = ./srcs

SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/free_displays.c $(SRCS_DIR)/drawlines.c \
$(SRCS_DIR)/ft_free.c $(SRCS_DIR)/init_window.c \
$(SRCS_DIR)/ft_pixelput.c $(SRCS_DIR)/get_time.c

OBJS = $(SRCS:.c=.o)

# Colors
BOLD_GREEN = \033[1;32m
BOLD_RED = \033[1;31m
RESET = \033[0m

all: $(NAME)
	@echo "$(BOLD_GREEN)Compilation completed!$(RESET)"

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	echo "$(NAME) successfully built!" || echo "Error: $(NAME) not found!"

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@if [ -d "$(MLX_DIR)" ]; then \
		make clean -C $(MLX_DIR) --no-print-directory; \
	fi
	@echo "$(BOLD_RED)Clean completed!$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@if [ -d "$(MLX_DIR)" ]; then \
		rm -rf $(MLX_DIR); \
	fi
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(BOLD_RED)fclean completed!$(RESET)"

re: fclean all
	@echo "$(BOLD_GREEN)Compilation redone!$(RESET)"

.PHONY: all clean fclean re
