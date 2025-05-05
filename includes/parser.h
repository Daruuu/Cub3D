#ifndef PARSER_H
# define PARSER_H

typedef struct s_position   t_position;
typedef struct  s_parser	t_parser;

//  PARSING FUNCTIONS

//  check_map.c
int         check_correct_parsing_map(char **argv);

//  free_functions.c
void        free_map(t_parser *map_info);
void        free_parser_struct(t_parser *parser);

#endif