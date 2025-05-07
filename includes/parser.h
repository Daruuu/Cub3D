#ifndef PARSER_H
# define PARSER_H

typedef struct s_position   t_position;
typedef struct s_parser     t_parser;
typedef struct s_game       t_game;

//  PARSING FUNCTIONS

//  check_extension.c
int         validate_path_map(char *argv);
int         map_format_border_check(char *path, t_parser *map_info);

//  check_map.c
int         check_correct_parsing_map(char **argv);

//  free_functions.c
void        free_map(t_parser *map_info);
void        free_parser_struct(t_parser *parser);

//  print_errors.c
void        handle_error(char *str, int size, t_parser *map, t_game *game);
void        handle_exit(char *str, int size);

//  parsing_utils.c
int         ft_open_map(char *path);
int         set_map_dimensions(t_parser *map_info);
int         check_map_dimensions(t_parser *map);

void        print_map_2d(t_parser *map_info);



//  parsing_files.c
int         read_map(char *path, t_parser *map_info);
int         read_file(char *path, t_parser *map_info);

void        fill_parser_info(t_parser *parser);


#endif