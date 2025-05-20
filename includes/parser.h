#ifndef PARSER_H
# define PARSER_H

typedef struct s_position   t_position;
typedef struct s_parser     t_parser;
typedef struct s_game       t_game;

// ===========================================
// ============== PARSER MAP =================
// ===========================================

//  check_extension_and_player.c
int         validate_path_map(char *argv);
void        get_player_init_pos(t_parser *map_data);

//  check_items.c
int         validation_items_in_map(t_parser *map_info);

// errors_handler.c
void        handle_error(char *str, int size, t_parser *map, t_game *game);
void        handle_exit(char *str);

//  extract_map.c
void        extract_map_from_file_map(t_parser *parser);

//  free_functions.c
void        free_parser_map(t_parser *parser);
void		free_matrix(char **map);
void        free_parser_struct(t_parser *parser);

//  parsing.c

// ===========================================
// ============ PARSER FILE ==================
// ===========================================

//  parsing_files.c
int         read_map(char *path, t_parser *map_info);
int         read_file(char *path, t_parser *map_info);
void        fill_parser_info(t_parser *parser);

//  parsing_utils.c
int         ft_open_map(char *path);
int         set_map_dimensions(t_parser *map_info);
int         check_map_dimensions(t_parser *map);

void        print_map_2d(t_parser *map_info);


//  parsing_textures.c

int			check_textures_and_colors(t_parser *parser);

#endif