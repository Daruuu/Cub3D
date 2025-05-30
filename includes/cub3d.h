#ifndef CUB3D_H 
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "parser.h"
# include "init.h"
# include "cub3d_utils.h"

typedef struct s_position
{
	int     x;
	int     y;
}	t_position;

typedef struct  s_parser
{
	char        **file_map;
	char        **map;
	int         items_map;
	char        player;
	int         rows;
	int         columns;
	char        *north;
	char        *south;
	char        *west;
	char        *east;
	char        *floor;
	char        *ceiling;
	int         rgb_floor[3];
	int         rgb_ceil[3];
	t_position position_player;
}   t_parser;

typedef struct s_image
{
    void        *mlx;
    void        *win;
    void        *img;
    void        *xmp_ptr;
    int         bit_per_pixel;
    int         len_line;
}   t_image;

typedef struct s_map
{
    t_parser    *parser;

}   t_map;

typedef struct s_game
{
	t_parser	*paser;
}   t_game;

//  INIT STRUCTS

//  init_parser.c
t_parser        *init_struct_parser(void);

#endif
