# ===================== PROJECT CONFIG ===================== #
NAME        = cub3D
NAME_BONUS	= cub3D_bonus
CC          = cc
RM          = rm -f

CFLAGS      = -Wall -Wextra -Werror
DEBUGFLAGS  = -g -fsanitize=address

UNAME       := $(shell uname)

# ===================== CONFIG EXTRA ===================== #
MAKEFLAGS   += -j$(shell nproc)

# ================== Flags ================== #
#PLAYER_SPEED_DEFAULT := 0.0045
PLAYER_SPEED_DEFAULT := 0.0015
PLAYER_SPEED_BONUS   := 0.0085

#ROTATION_SPEED_DEFAULT := 0.0045
ROTATION_SPEED_DEFAULT := 0.0010
ROTATION_SPEED_BONUS   := 0.009

CFLAGS_MANDATORY	:= $(CFLAGS) -DPLAYER_SPEED=$(PLAYER_SPEED_DEFAULT) -DROTATION_SPEED=$(ROTATION_SPEED_DEFAULT)
CFLAGS_BONUS		:= $(CFLAGS) -DPLAYER_SPEED=$(PLAYER_SPEED_BONUS) -DROTATION_SPEED=$(ROTATION_SPEED_BONUS)

DEPDIR      := .deps
DEP_FLAGS    = -MMD -MP -MF $(DEPDIR)/$*.d  # <--- generate dependency files in .deps/

DEBUG   ?= 0
SANITIZE?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -g -DDEBUG
endif

ifeq ($(SANITIZE), 1)
	CFLAGS += -fsanitize=address -fsanitize=undefined
endif

# ===================== PATHS ===================== #
SRC_DIR		= srcs
PATH_MLX    = mlx
PATH_DELAY  = $(SRC_DIR)/delay
PATH_BASS   = bass

# ===================== SOURCES ===================== #
#	$(SRC_DIR)/render/cub_bitmap.c
SRC_CORE = \
	$(SRC_DIR)/parser/cub_file.c \
	$(SRC_DIR)/parser/cub_map_parser.c \
	$(SRC_DIR)/parser/cub_map_setter.c \
	$(SRC_DIR)/parser/cub_parser.c \
	$(SRC_DIR)/parser/cub_setter.c \
	$(SRC_DIR)/pathfinder/cub_astar.c \
	$(SRC_DIR)/pathfinder/cub_node.c \
	$(SRC_DIR)/pathfinder/cub_node_helper.c \
	$(SRC_DIR)/pathfinder/cub_path.c \
	$(SRC_DIR)/pathfinder/cub_pathfinder.c \
	$(SRC_DIR)/pathfinder/cub_star_cardinal.c \
	$(SRC_DIR)/render/cub_blur.c \
	$(SRC_DIR)/render/raycast_engine.c \
	$(SRC_DIR)/render/raycast_collision.c \
	$(SRC_DIR)/render/raycast_dda.c \
	$(SRC_DIR)/render/render_floor.c \
	$(SRC_DIR)/render/render_textures.c \
	$(SRC_DIR)/render/cub_hud.c \
	$(SRC_DIR)/render/cub_minimap.c \
	$(SRC_DIR)/render/cub_xquartz_layer.c \
	$(SRC_DIR)/sprites/cub_doors.c \
	$(SRC_DIR)/sprites/cub_goomba.c \
	$(SRC_DIR)/sprites/cub_sprite_list.c \
	$(SRC_DIR)/sprites/cub_sprites.c \
	$(SRC_DIR)/utils/cub_checker.c \
	$(SRC_DIR)/utils/cub_cleaner.c \
	$(SRC_DIR)/utils/cub_error.c \
	$(SRC_DIR)/utils/cub_keybinds.c \
	$(SRC_DIR)/utils/cub_line_reader.c \
	$(SRC_DIR)/utils/cub_line_reader_helper.c \
	$(SRC_DIR)/utils/cub_rot.c \
	$(SRC_DIR)/utils/cub_setup.c \
	$(SRC_DIR)/utils/cub_utils.c \
	$(SRC_DIR)/utils/cub_utils2.c \
	$(SRC_DIR)/utils/cub_utils3.c \
	$(SRC_DIR)/utils/cub_utils4.c \
	$(SRC_DIR)/utils/cub_utils5.c \
	$(SRC_DIR)/utils/cub_vec.c \
	$(SRC_DIR)/utils/cub_vec2.c \
	$(SRC_DIR)/world/cub_cardinal.c \
	$(SRC_DIR)/world/cub_collide.c \
	$(SRC_DIR)/world/cub_map.c \
	$(SRC_DIR)/world/cub_player.c \
	$(SRC_DIR)/world/cub_portal.c \
	$(SRC_DIR)/world/cub_portal2.c \
	$(SRC_DIR)/world/portal_list.c \
	main.c

SRC_BONUS = \
	bonus/cub_sound_bonus.c \
	bonus/cub_other_bonus.c

SRC_OPTIONAL = \
	$(SRC_DIR)/other/cub_other.c \
	$(SRC_DIR)/other/cub_sound.c

# ===================== OBJECTS ===================== #
OBJS_CORE     = ${SRC_CORE:.c=.o}
OBJS_BONUS    = ${SRC_BONUS:.c=.o}
OBJS_OPTIONAL = ${SRC_OPTIONAL:.c=.o}

# ===================== DEPENDENCIES (.d files) ===================== #
DEPS_CORE     = $(SRC_CORE:.c=.d)
DEPS_BONUS    = $(SRC_BONUS:.c=.d)
DEPS_OPTIONAL = $(SRC_OPTIONAL:.c=.d)
DEPS          = $(DEPS_CORE) $(DEPS_BONUS) $(DEPS_OPTIONAL)

# ===================== FLAGS ===================== #
FLAGS_BASE = -I$(PATH_MLX) -L$(PATH_MLX) -lmlx -lm -lXext -lX11 \
			 -I$(PATH_DELAY) -L$(PATH_DELAY) -ldelay \
			 -Wl,-rpath=./$(PATH_BASS)/,-rpath=./$(PATH_MLX)/,-rpath=./$(PATH_DELAY)/

FLAGS_BONUS = -I$(PATH_BASS) -L$(PATH_BASS) -lbass \
			  -I$(PATH_DELAY) -L$(PATH_DELAY) -ldelay \
			  $(FLAGS_BASE)

# ===================== RULES ===================== #
all: $(NAME)

$(NAME): $(OBJS_CORE) $(OBJS_OPTIONAL)
	$(MAKE) -C $(PATH_MLX)
	$(MAKE) -C $(PATH_DELAY)
	$(CC) $(CFLAGS_MANDATORY) -o $(NAME) $(OBJS_CORE) $(OBJS_OPTIONAL) $(FLAGS_BASE)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_CORE:.o=_bonus.o) $(OBJS_BONUS:.o=_bonus.o)
	$(MAKE) -C $(PATH_MLX)
	$(MAKE) -C $(PATH_DELAY)
	$(CC) $(CFLAGS_BONUS) -o $(NAME_BONUS) $^ $(FLAGS_BONUS)

# ===================== COMPILATION WITH DEPENDENCIES ===================== #
%.o: %.c Makefile cub3D.h include/includes_cub.h
	@mkdir -p $(dir $@)                     # Crear carpeta para .o
	@mkdir -p $(DEPDIR)/$(dir $<)          # Crear carpeta para .d
	$(CC) $(CFLAGS_MANDATORY) $(DEP_FLAGS) -I$(PATH_MLX) -I$(PATH_BASS) -Iinclude -Iparser -Ipathfinder -Irender -Iutils -Iworld -Iother -c $< -o $@ -D LINUX=true

# Regla para bonus (se compila a _bonus.o para no chocar con mandatory)
%_bonus.o: %.c Makefile cub3D.h include/includes_cub.h
	@mkdir -p $(dir $@)
	@mkdir -p $(DEPDIR)/$(dir $<)
	$(CC) $(CFLAGS_BONUS) $(DEP_FLAGS) -I$(PATH_MLX) -I$(PATH_BASS) -Iinclude -Iparser -Ipathfinder -Irender -Iutils -Iworld -Iother -c $< -o $@ -D LINUX=true


# ===================== CLEAN ===================== #
clean:
	$(MAKE) -C $(PATH_MLX) clean
	$(MAKE) -C $(PATH_DELAY) clean
	$(RM) $(OBJS_CORE) $(OBJS_BONUS) $(OBJS_OPTIONAL)
	$(RM) $(OBJS_CORE:.o=_bonus.o) $(OBJS_BONUS:.o=_bonus.o)
	$(RM) -r $(DEPDIR)

fclean: clean
	$(MAKE) -C $(PATH_DELAY) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

norm:
	@echo "🔍 Norminette: $(SRC_CORE) $(SRC_BONUS) $(SRC_OPTIONAL)" main.c cub3D.h include/includes_cub.h
	@norminette $(SRC_CORE) $(SRC_BONUS) $(SRC_OPTIONAL) main.c cub3D.h include/includes_cub.h

# ===================== INCLUDE DEPENDENCIES ===================== #
# Incluir todos los archivos .d generados en .deps
-include $(DEPS)

.PHONY: all clean fclean re bonus norm
