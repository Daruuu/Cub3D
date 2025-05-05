# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:22:56 by anamedin          #+#    #+#              #
#    Updated: 2025/05/05 11:15:55 by dasalaza         ###   ########.fr        #
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
SRC_INIT_DIR = ${SRC_DIR}/init
SRC_PARSER_DIR = ${SRC_DIR}/parser 

OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
CUB3D_H = includes/cub3d.h

SRC =	$(SRC_DIR)/main.c \
	$(SRC_INIT_DIR)/init_mlx.c \
	$(SRC_INIT_DIR)/init_structs.c \
	$(SRC_PARSER_DIR)/check_items.c \
	$(SRC_PARSER_DIR)/check_map.c \
	$(SRC_PARSER_DIR)/check_player.c \
	$(SRC_PARSER_DIR)/check_utils.c \
	$(SRC_PARSER_DIR)/map_extension.c 

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRC)))


LIBFT = $(LIBFT_DIR)/libft.a

# ==================================== #

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(CUB3D_H) Makefile
# 	@mkdir -p $(dir $@)		#extract each dir inside srcs like init
# 	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
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
