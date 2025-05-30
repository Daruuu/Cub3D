/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:06:42 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 14:42:06 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_position	t_position;
typedef struct s_parser		t_parser;
typedef struct s_game		t_game;

// ===========================================
// ============== PARSER MAP =================
// ===========================================

//  check_extension_and_player.c
int			validate_map_filename(char *filename);
void		get_player_init_pos(t_parser *map_data);

//  check_items.c
int			validate_map(t_parser *parser);

//  check_player.c

// errors_handler.c
void		handle_error(char *str, int size, t_parser *map, t_game *game);
void		handle_exit(char *str);

//  extract_map.c
void		extract_map_from_file_map(t_parser *parser);

//  free_functions.c
void		free_parser_map(t_parser *parser);
void		free_matrix(char **map);
void		free_parser_struct(t_parser *parser);

//  parsing.c
char		**duplicate_map_matrix(t_parser *parser);
int parsing(t_parser* parser);
int			count_file_size(char *path);

// ===========================================
// ============ PARSER FILE ==================
// ===========================================

//  parse_files.c
char		*read_file_content(char *path, int size);
int			read_file(char *path, t_parser *parser);

//  parse_utils.c
int			ft_open_map(char *path);
int			get_max_columns(char **map, int rows);

//  parse_textures.c
int			check_textures_and_colors(t_parser *parser);
void        parse_lines_of_textures(t_parser *parser);

#endif
