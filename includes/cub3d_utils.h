#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

/*--------------------Error and free------------------*/
# define ERROR_INVALID_ARGS "Error: Incorrect arguments.\n"
# define INVALID_LEN_FILE_MAP "Error: Map filename too short.\n"
# define INVALID_MAP_EXTENSION "Error: Extension invalid, expected '.cub'\n"
# define ERROR_INVALID_FILENAME_CHARS   "Error: Filename contains invalid characters.\n"
# define ERROR_OPEN_FILE_MAP "Error: Map file could not be opened.\n"
# define ERROR_EMPTY_FILE_MAP "Error: File map is empty.\n"


# define INVALID_MAP_SIZE "Error: Invalid size map\n"
# define ERROR_INVALID_MAP_ROWS "Error: Invalid rows\n"
# define ERROR_INVALID_MAP_COLS "Error: Invalid columns\n"

# define ERROR_MEMORY_ALLOCATION "Error: Memory allocation failed\n"

# define ERROR_WALLS_IN_MAP "Error: Invalid WALLS in map.\n"
# define ERROR_ITEMS_IN_MAP "Error: Invalid ITEM in map.\n"

# define ERROR_INVALID_NORTH_TEXTURE "Error: Invalid texture NORTH\n"
# define ERROR_INVALID_SOUTH_TEXTURE "Error: Invalid texture SOUTH\n"
# define ERROR_INVALID_WEST_TEXTURE "Error: Invalid texture WEST\n"
# define ERROR_INVALID_EAST_TEXTURE "Error: Invalid texture EAST\n"

# define ERROR_INVALID_FLOOR_TEXTURE "Error: Invalid format of FLOOR\n"
# define ERROR_INVALID_CEILING_TEXTURE "Error: Invalid format of CEIL\n"

# define ERROR_ITEM_NORTH "Error: Invalid items NORTH.\n"
# define ERROR_ITEM_SOUTH "Error: Invalid items SOUTH.\n"
# define ERROR_ITEM_WEST "Error: Invalid items WEST.\n"
# define ERROR_ITEM_EAST "Error: Invalid items EAST.\n"

# define ERROR_TABULATION_IN_MAP "Error: A tabulation exist in map.\n"
/*--------------------Error and exit------------------*/

/*--------------------Error items in map------------------*/

/*-------------------- ITEMS ASSIGN ------------------*/
# define WALL '1'
# define FLOOR '0'

/*-------------------- ITEMS ASSIGN PLAYER ------------------*/
# define NORTH  'N'
# define SOUTH  'S'
# define WEST   'W'
# define EAST   'E'

// Direcciones del jugador
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3
# define BACK 2
# define FRONT 3

/*-------------------- SIZE OF SPRITE ------------------*/
# define TILE_SIZE 32

/*-------------------- XPM PATHS -----------------------*/

# define PLAYER_FRONT_XPM "textures/player_front.xpm"
# define PLAYER_LEFT_XPM "textures/player_left.xpm"
# define PLAYER_RIGHT_XPM "textures/player_right.xpm"
# define PLAYER_BACK_XPM "textures/player_back.xpm"
# define COIN_XPM "textures/coin.xpm"
# define FLOOR_XPM "textures/floor.xpm"
# define WALL_XPM "textures/wall.xpm"
# define EXIT_CLOSED_XPM "textures/exit-closed.xpm"
# define OPEN_EXIT_XPM "textures/open-exit.xpm"

/*-------------------- KEYS EVENTS ------------------*/
# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_Q      113

# define KEY_ESC    65307
# define KEY_UP     65362
# define KEY_DOWN   65364
# define KEY_LEFT   65361
# define KEY_RIGHT  65363

#endif