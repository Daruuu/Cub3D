# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:22:56 by anamedin          #+#    #+#              #
#    Updated: 2025/05/12 21:17:10 by dasalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== Libs ========== #
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
HEADER_H = includes/cub3d.h


# ========== Configuración general ========== #
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) -I/usr/include -fsanitize=address

# ========== Directorios ========== #
SRC_DIR = srcs
SRC_INIT = $(SRC_DIR)/init
SRC_PARSER_FILE = $(SRC_DIR)/parser_file
SRC_PARSER_MAP = $(SRC_DIR)/parser_map

OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

# ========== Archivos fuente ========== #
SRC =	$(SRC_DIR)/main.c \
	$(SRC_INIT)/init_mlx.c \
	$(SRC_INIT)/init_parser.c \
	$(SRC_INIT)/init_structs.c \
	$(SRC_INIT)/print_structs.c \
	$(SRC_PARSER_FILE)/parsing_file.c \
	$(SRC_PARSER_FILE)/parsing_textures.c \
	$(SRC_PARSER_FILE)/parsing_utils.c \
	$(SRC_PARSER_MAP)/check_extension.c \
	$(SRC_PARSER_MAP)/check_items.c \
	$(SRC_PARSER_MAP)/check_map.c \
	$(SRC_PARSER_MAP)/check_player.c \
	$(SRC_PARSER_MAP)/check_utils.c \
	$(SRC_PARSER_MAP)/free_functions.c \
	$(SRC_PARSER_MAP)/parsing.c \
	$(SRC_PARSER_MAP)/print_errors.c 

# ========== Archivos objeto ========== #
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRC)))

# ========== Reglas ========== #
all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_H)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# ========== Limpieza ========== #
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re