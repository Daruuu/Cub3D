# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:22:56 by anamedin          #+#    #+#              #
#    Updated: 2025/05/30 14:42:52 by dasalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===================== PROJECT CONFIG ===================== #

NAME        = cub3D
CC          = gcc
RM          = rm -f

CFLAGS      = -Wall -Wextra -Werror
DEBUGFLAGS  = -g -fsanitize=address

UNAME       := $(shell uname)

# Paths
PATH_MLX    = mlx
PATH_DELAY  = delay
PATH_BASS   = bass

# ===================== SOURCES ===================== #

# Core sources
SRC_CORE = \
	parser/cub_file.c \
	parser/cub_map_parser.c \
	parser/cub_map_setter.c \
	parser/cub_parser.c \
	parser/cub_setter.c \
	pathfinder/cub_astar.c \
	pathfinder/cub_node.c \
	pathfinder/cub_node_helper.c \
	pathfinder/cub_path.c \
	pathfinder/cub_pathfinder.c \
	pathfinder/cub_star_cardinal.c \
	render/cub_bitmap.c \
	render/cub_blur.c \
	render/cub_floor.c \
	render/cub_hud.c \
	render/cub_minimap.c \
	render/cub_raycast.c \
	render/cub_raycast2.c \
	render/cub_raycast3.c \
	render/cub_texture.c \
	render/cub_xquartz_layer.c \
	sprites/cub_doors.c \
	sprites/cub_goomba.c \
	sprites/cub_sprite_list.c \
	sprites/cub_sprites.c \
	utils/cub_checker.c \
	utils/cub_cleaner.c \
	utils/cub_error.c \
	utils/cub_keybinds.c \
	utils/cub_line_reader.c \
	utils/cub_line_reader_helper.c \
	utils/cub_rot.c \
	utils/cub_setup.c \
	utils/cub_utils.c \
	utils/cub_utils2.c \
	utils/cub_utils3.c \
	utils/cub_utils4.c \
	utils/cub_utils5.c \
	utils/cub_vec.c \
	utils/cub_vec2.c \
	world/cub_cardinal.c \
	world/cub_collide.c \
	world/cub_map.c \
	world/cub_player.c \
	world/cub_portal.c \
	world/cub_portal2.c \
	world/cub_portal_list.c \
	main.c

# Bonus sources
SRC_BONUS = \
	bonus/cub_sound_bonus.c \
	bonus/cub_other_bonus.c

# Non-bonus sources (alternative to bonus)
SRC_OPTIONAL = \
	other/cub_other.c \
	other/cub_sound.c

# ===================== HEADERS ===================== #

HDR_FILES = \
	bonus/cub_sound_bonus.h \
	delay/libdelay.h \
	include/bmp_partial_alligned_header.h \
	include/cub_cardinal_enum.h \
	include/cub_floor_render.h \
	include/cub_keybinds_struct.h \
	include/cub_mouseover_struct.h \
	include/cub_player_struct.h \
	include/cub_portal_struct.h \
	include/cub_raycast_struct.h \
	include/cub_sprite_struct.h \
	include/cub_sprite_type.h \
	include/cub_walls.h \
	main.h \
	other/cub_sound.h \
	parser/cub_file.h \
	parser/cub_map_parser.h \
	parser/cub_map_setter.h \
	parser/cub_parser.h \
	parser/cub_setter.h \
	pathfinder/cub_astar.h \
	pathfinder/cub_path.h \
	pathfinder/cub_pathfinder.h \
	pathfinder/cub_star_cardinal.h \
	pathfinder/cub_node.h \
	render/cub_bitmap.h \
	render/cub_blur.h \
	render/cub_floor.h \
	render/cub_hud.h \
	render/cub_minimap.h \
	render/cub_raycast.h \
	render/cub_texture.h \
	render/cub_xquartz_layer.h \
	sprites/cub_doors.h \
	sprites/cub_goomba.h \
	sprites/cub_sprite_list.h \
	sprites/cub_sprites.h \
	utils/cub_checker.h \
	utils/cub_cleaner.h \
	utils/cub_error.h \
	utils/cub_keybinds.h \
	utils/cub_rot.h \
	utils/cub_setup.h \
	utils/cub_utils.h \
	utils/cub_vec.h \
	utils/cub_line_reader.h \
	world/cub_cardinal.h \
	world/cub_collide.h \
	world/cub_map.h \
    world/cub_player.h \
    world/cub_portal.h \
    world/cub_portal_list.h \
    cub3D.h

    # ===================== OBJECTS ===================== #

OBJS_CORE      = ${SRC_CORE:.c=.o}
OBJS_BONUS     = ${SRC_BONUS:.c=.o}
OBJS_OPTIONAL  = ${SRC_OPTIONAL:.c=.o}

# ===================== FLAGS ===================== #

#FLAGS_BASE = -I$(PATH_MLX) -L$(PATH_MLX) -lmlx -lm -lXext -lX11 \
#			 -Wl,-rpath=./$(PATH_BASS)/,-rpath=./$(PATH_MLX)/,-rpath=./$(PATH_DELAY)/

FLAGS_BASE = -I$(PATH_MLX) -L$(PATH_MLX) -lmlx -lm -lXext -lX11 \
			 -I$(PATH_DELAY) -L$(PATH_DELAY) -ldelay \
			 -Wl,-rpath=./$(PATH_BASS)/,-rpath=./$(PATH_MLX)/,-rpath=./$(PATH_DELAY)/


FLAGS_DEBUG = $(FLAGS_BASE) $(DEBUGFLAGS)

FLAGS_BONUS = -I$(PATH_BASS) -L$(PATH_BASS) -lbass \
			  -I$(PATH_DELAY) -L$(PATH_DELAY) -ldelay \
			  $(FLAGS_BASE)

    # ===================== RULES ===================== #

all: $(NAME)

#.c.o: Makefile cub3D.h
.c.o:
	$(CC) $(CFLAGS) -I$(PATH_MLX) -I$(PATH_BASS) -c $< -o ${<:.c=.o} -D LINUX=true

#$(NAME): $(OBJS_CORE) $(OBJS_OPTIONAL)
#		make -C $(PATH_MLX)
#		$(CC) $(CFLAGS) -o $(NAME) $(OBJS_CORE) $(OBJS_OPTIONAL) $(FLAGS_BASE)

$(NAME): $(OBJS_CORE) $(OBJS_OPTIONAL)
		make -C $(PATH_MLX)
		make -C $(PATH_DELAY)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS_CORE) $(OBJS_OPTIONAL) $(FLAGS_BASE)

bonus: $(OBJS_CORE) $(OBJS_BONUS)
		make -C $(PATH_MLX)
		make -C $(PATH_DELAY)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS_CORE) $(OBJS_BONUS) $(FLAGS_BONUS)

clean:
		make -C $(PATH_MLX) clean
		make -C $(PATH_DELAY) clean
		$(RM) $(OBJS_CORE) $(OBJS_BONUS) $(OBJS_OPTIONAL)

fclean: clean
		make -C $(PATH_DELAY) fclean
		$(RM) $(NAME)

re: fclean all

norm:
	@echo "🔍 Norminette: $(SRC_CORE) $(SRC_BONUS) $(SRC_OPTIONAL) $(HDR_FILES)"
	@norminette $(SRC_CORE) $(SRC_BONUS) $(SRC_OPTIONAL) $(HDR_FILES)

.PHONY: bonus all clean fclean re norm
