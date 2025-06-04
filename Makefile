# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:22:56 by anamedin          #+#    #+#              #
#    Updated: 2025/06/04 21:43:11 by dasalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== Libs ========== #
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ========== Configuración general ========== #
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) -I/usr/include -g -fsanitize=address

TEST_FLAGS = -fsanitize=address -g -Wall -Wextra -Werror -lm

# ========== Directorios ========== #
SRC_DIR = srcs
SRC_INIT = $(SRC_DIR)/init
SRC_PARSER_FILE = $(SRC_DIR)/parser_file
SRC_PARSER_MAP = $(SRC_DIR)/parser_map

OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
CUB3D_H = includes/cub3d.h

# ========== Testing Header ========== #
TESTING_H = testing/testing.h

# ========== Archivos fuente ========== #
SRC =	$(SRC_DIR)/main.c \
	$(SRC_INIT)/init_mlx.c \
	$(SRC_INIT)/init_structs.c \
	$(SRC_INIT)/print_structs.c \
	$(SRC_PARSER_FILE)/parse_file.c \
	$(SRC_PARSER_FILE)/parse_textures.c \
	$(SRC_PARSER_FILE)/parse_textures_utils.c \
	$(SRC_PARSER_FILE)/parse_utils.c \
	$(SRC_PARSER_MAP)/check_extension_and_player.c \
	$(SRC_PARSER_MAP)/error_handler.c \
	$(SRC_PARSER_MAP)/extract_map.c \
	$(SRC_PARSER_MAP)/free_functions.c \
	$(SRC_PARSER_MAP)/map_utils.c \
	$(SRC_PARSER_MAP)/map_validation.c \
	$(SRC_PARSER_MAP)/parsing.c

# ========== Archivos objeto ========== #
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRC)))

# ================= Testing =================== #

SRC_TESTING = testing/unity.c \
		   testing/setup_testing.c

OBJ_TEST = $(patsubst testing/%.c, $(OBJ_DIR)/testing/%.o, $(SRC_TESTING))

OBJ_TESTING = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRC_TESTING)))

# ========== Rules ========== #
#all: $(NAME)
all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(CUB3D_H) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ========== Extern libs ========== #

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# ========== Object test ========== #

$(OBJ_DIR)/testing/%.o: testing/%.c $(TESTING_H)
	@mkdir -p $(dir $@)
	$(CC)  -c $< -o $@

TEST_MAIN = testing/test_main.c

# Filtra el main.o del listado de objetos del proyecto
OBJ_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJ))

test: $(OBJ_TEST) $(OBJ_NO_MAIN)
	$(CC) -o test $(TEST_MAIN) $(OBJ_TEST) \
	$(OBJ_NO_MAIN) $(LIBFT) $(TEST_FLAGS) -Iincludes -I$(LIBFT_DIR)

# ========== Clean ========== #
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re
