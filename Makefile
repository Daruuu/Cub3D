# ===================== PROJECT CONFIG ===================== #
NAME        = cub3D
NAME_BONUS	= cub3D_bonus

CC          = cc
RM          = rm -f
#AR          = ar rcs

# Compiler flags
CFLAGS      = -Wall -Wextra -Werror
DEBUG_FLAGS  = -g -fsanitize=address -fsanitize=undefined
HEADERS		= cub3D.h include/includes_cub.h

# Detect OS
UNAME       := $(shell uname)

# ===================== CONFIG EXTRA ===================== #
# Parallel compilation
MAKEFLAGS   += -j$(shell nproc)

# ===================== GAME CONFIGURATION ===================== #
# Player speeds
PLAYER_SPEED_DEFAULT := 0.0015
PLAYER_SPEED_BONUS   := 0.0085

# Rotation speeds  
ROTATION_SPEED_DEFAULT := 0.0010
ROTATION_SPEED_BONUS   := 0.009

# Build configuration flags
CFLAGS_MANDATORY	:= $(CFLAGS) -DPLAYER_SPEED=$(PLAYER_SPEED_DEFAULT) -DROTATION_SPEED=$(ROTATION_SPEED_DEFAULT)
CFLAGS_BONUS		:= $(CFLAGS) -DPLAYER_SPEED=$(PLAYER_SPEED_BONUS) -DROTATION_SPEED=$(ROTATION_SPEED_BONUS)

# ===================== DEPENDENCY MANAGEMENT ===================== #
DEPDIR      := .deps
DEP_FLAGS    = -MMD -MP -MF $(DEPDIR)/$*.d  # <--- generate dependency files in .deps/

# Debug and sanitize options
DEBUG   ?= 0
SANITIZE?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -g -DDEBUG
endif

ifeq ($(SANITIZE), 1)
	CFLAGS += $(DEBUG_FLAGS)
endif

# ===================== PATHS ===================== #
SRC_DIR		= srcs
PATH_MLX    = mlx
PATH_DELAY  = $(SRC_DIR)/delay
PATH_BASS   = bass
INCLUDE_DIR = include

# Include directories
INCLUDES    = -I$(PATH_MLX) -I$(PATH_BASS) -I$(INCLUDE_DIR) \
			  -I$(SRC_DIR)/parser -I$(SRC_DIR)/pathfinder \
			  -I$(SRC_DIR)/render -I$(SRC_DIR)/utils \
			  -I$(SRC_DIR)/world -I$(SRC_DIR)/other \
			  -I$(SRC_DIR)/game -I$(SRC_DIR)/game_sprites \
			  -I$(SRC_DIR)/sound \
			  -I$(SRC_DIR)/graphics -I$(SRC_DIR)/math \
			  -I$(SRC_DIR)/io -I$(SRC_DIR)/input -I$(SRC_DIR)/system

# ===================== SOURCES BY FOLDER ===================== #
# Main entry point
SRC_MAIN = main.c

# IO sources
SRC_FILE_LOADER = \
	$(SRC_DIR)/file_loader/check_file_map.c \
	$(SRC_DIR)/file_loader/load_file.c \
	$(SRC_DIR)/file_loader/load_file_helper.c \
	$(SRC_DIR)/file_loader/string_utils.c

# Game logic sources
SRC_GAME = \
	$(SRC_DIR)/game/game_collision.c \
	$(SRC_DIR)/game/game_directions.c \
	$(SRC_DIR)/game/game_map.c \
	$(SRC_DIR)/game/game_player.c \
	$(SRC_DIR)/game/game_portal.c \
	$(SRC_DIR)/game/game_portal_advance.c \
	$(SRC_DIR)/game/game_portal_render.c

# Game sprites sources
SRC_GAME_SPRITES = \
	$(SRC_DIR)/game_sprites/game_sprite_door.c \
	$(SRC_DIR)/game_sprites/game_sprite_enemy.c \
	$(SRC_DIR)/game_sprites/game_sprite_manager.c \
	$(SRC_DIR)/game_sprites/game_sprite_renderer.c

# Graphics sources
SRC_GRAPHICS = \
	$(SRC_DIR)/graphics/color_operations.c \
	$(SRC_DIR)/graphics/image_operations.c \
	$(SRC_DIR)/graphics/rendering_primitives.c

# System sources
SRC_INIT_GAME = \
	$(SRC_DIR)/init_game/error_handler.c \
	$(SRC_DIR)/init_game/init_game.c

# Input sources
SRC_INPUT = \
	$(SRC_DIR)/input/input_handler.c

# Parser sources
SRC_PARSER = \
	$(SRC_DIR)/parser/parser_file_loader.c \
	$(SRC_DIR)/parser/parser_main.c \
	$(SRC_DIR)/parser/parser_map_parser.c \
	$(SRC_DIR)/parser/parser_map_setter.c \
	$(SRC_DIR)/parser/parser_map_validator.c \
	$(SRC_DIR)/parser/parser_memory_cleanup.c \
	$(SRC_DIR)/parser/parser_setter.c

# Render engine sources
SRC_RENDER = \
	$(SRC_DIR)/render/raycast_collision.c \
	$(SRC_DIR)/render/raycast_dda.c \
	$(SRC_DIR)/render/raycast_engine.c \
	$(SRC_DIR)/render/render_blur.c \
	$(SRC_DIR)/render/render_floor.c \
	$(SRC_DIR)/render/render_hud.c \
	$(SRC_DIR)/render/render_macos_layer.c \
	$(SRC_DIR)/render/render_minimap.c \
	$(SRC_DIR)/render/render_textures.c

# Math sources
SRC_MATH = \
	$(SRC_DIR)/math/vector_math.c \
	$(SRC_DIR)/math/vector_math_utils.c \
	$(SRC_DIR)/math/math_utils.c \
	$(SRC_DIR)/math/rotation_math.c

# Combined core sources (LEGACY STRUCTURE)
SRC_CORE = $(SRC_MAIN) \
	$(SRC_FILE_LOADER) $(SRC_GAME) $(SRC_GAME_SPRITES) $(SRC_GRAPHICS) \
	$(SRC_INIT_GAME) $(SRC_INPUT) $(SRC_MATH) \
	$(SRC_PARSER) $(SRC_RENDER)

SRC_BONUS = \
	bonus/cub_sound_bonus.c \
	bonus/cub_other_bonus.c

SRC_AUDIO = \
	$(SRC_DIR)/sound/bonus_features.c \
	$(SRC_DIR)/sound/audio_system.c

# ===================== OBJECTS ===================== #
OBJS_CORE     = ${SRC_CORE:.c=.o}
OBJS_BONUS    = ${SRC_BONUS:.c=.o}
OBJS_OPTIONAL = ${SRC_AUDIO:.c=.o}

# ===================== DEPENDENCIES (.d files) ===================== #
DEPS_CORE     = $(SRC_CORE:.c=.d)
DEPS_BONUS    = $(SRC_BONUS:.c=.d)
DEPS_OPTIONAL = $(SRC_AUDIO:.c=.d)
DEPS          = $(DEPS_CORE) $(DEPS_BONUS) $(DEPS_OPTIONAL)

# ===================== LINKING FLAGS ===================== #
# Base libraries and paths
LDFLAGS_BASE = -L$(PATH_MLX) -L$(PATH_DELAY) \
			   -Wl,-rpath=./$(PATH_BASS)/,-rpath=./$(PATH_MLX)/,-rpath=./$(PATH_DELAY)/

# Library flags
LIBS_BASE = -lmlx -lm -lXext -lX11 -ldelay
LIBS_BONUS = -lbass

# Combined flags
FLAGS_BASE = $(INCLUDES) $(LDFLAGS_BASE) $(LIBS_BASE)
FLAGS_BONUS = $(INCLUDES) -I$(PATH_BASS) -L$(PATH_BASS) $(LDFLAGS_BASE) $(LIBS_BONUS) $(LIBS_BASE)

# Default target
all: $(NAME)

# Build mandatory version
$(NAME): $(OBJS_CORE) $(OBJS_OPTIONAL) | build-deps
#	@echo "🔨 Building $(NAME)..."
	$(CC) $(CFLAGS_MANDATORY) -o $@ $^ $(FLAGS_BASE)
#	@echo "✅ $(NAME) built successfully!"

# Build bonus version
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_CORE:.o=_bonus.o) $(OBJS_BONUS:.o=_bonus.o) | build-deps
	#@echo "🔨 Building $(NAME_BONUS)..."
	$(CC) $(CFLAGS_BONUS) -o $@ $^ $(FLAGS_BONUS)
#	@echo "✅ $(NAME_BONUS) built successfully!"

# Build dependencies
build-deps:
#	@echo "📦 Building dependencies..."
	$(MAKE) -C $(PATH_MLX) > /dev/null 2>&1
	$(MAKE) -C $(PATH_DELAY) > /dev/null 2>&1

# ===================== COMPILATION RULES ===================== #
# Compile mandatory objects
%.o: %.c Makefile cub3D.h include/includes_cub.h
	@mkdir -p $(dir $@)
	@mkdir -p $(DEPDIR)/$(dir $<)
	@echo "🔨 Compiling $<..."
	$(CC) $(CFLAGS_MANDATORY) $(DEP_FLAGS) $(INCLUDES) -c $< -o $@ -D LINUX=true

# Compile bonus objects
%_bonus.o: %.c Makefile cub3D.h include/includes_cub.h
	@mkdir -p $(dir $@)
	@mkdir -p $(DEPDIR)/$(dir $<)
	#@echo "🔨 Compiling $< (bonus)..."
	$(CC) $(CFLAGS_BONUS) $(DEP_FLAGS) $(INCLUDES) -c $< -o $@ -D LINUX=true

# ===================== CLEAN ===================== #
clean:
#	@echo "🧹 Cleaning object files..."
	$(MAKE) -C $(PATH_MLX) clean
	$(MAKE) -C $(PATH_DELAY) clean
	$(RM) $(OBJS_CORE) $(OBJS_BONUS) $(OBJS_OPTIONAL)
	$(RM) $(OBJS_CORE:.o=_bonus.o) $(OBJS_BONUS:.o=_bonus.o)
	$(RM) -r $(DEPDIR)
#	@echo "✅ Clean completed!"

fclean: clean
#	@echo "🧹 Full cleaning..."
	$(MAKE) -C $(PATH_DELAY) fclean
	$(RM) $(NAME) $(NAME_BONUS)
#	@echo "✅ Full clean completed!"

re: fclean all
#	@echo "🔄 Rebuilding everything..."
	 @$(MAKE) all

norm:
	@echo "🔍 Norminette: $(SRC_CORE) $(SRC_BONUS) $(SRC_AUDIO)" main.c cub3D.h include/includes_cub.h
	@norminette $(SRC_CORE) $(SRC_BONUS) $(SRC_AUDIO) main.c cub3D.h include/includes_cub.h

# ===================== UTILITY RULES ===================== #
# Debug build
debug:
	@echo "🐛 Building debug version..."
	@$(MAKE) DEBUG=1

# Sanitize build
sanitize:
	@echo "🧹 Building sanitized version..."
	@$(MAKE) SANITIZE=1

# ===================== DEPENDENCY INCLUSION ===================== #
# Include all generated .d files from .deps
-include $(DEPS)

# ===================== BUILD RULES ===================== #
.PHONY: all bonus clean fclean re norm debug sanitize help
