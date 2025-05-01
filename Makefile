# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:22:56 by anamedin          #+#    #+#              #
#    Updated: 2025/05/01 12:09:34 by dasalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================= CONFIG==================== #

INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ===================================== #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) $(INCLUDES) #-fsanitize=address

SRC_DIR = srcs
OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
SO_LONG_H = includes/cub3d.h

SRC =	$(SRC_DIR)/main.c



OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

# ==================================== #

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(SO_LONG_H)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ==================================== #
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# ==================================== #
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
