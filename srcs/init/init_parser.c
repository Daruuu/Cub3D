#include "../../includes/cub3d.h"

t_parser    *init_struct_parser(void)
{
    t_parser    parser;

    parser.map = NULL;
    parser.north = NULL;
    parser.south = NULL;
    parser.east = NULL;
    parser.west = NULL;
    parser.floor = NULL;
    parser.ceiling = NULL;
    parser.position_player.x = -1;
    parser.position_player.y = -1;

    return (&parser);
}