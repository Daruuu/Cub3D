/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:56:04 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 16:01:30 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_position	t_position;
typedef struct s_parser		t_parser;
typedef struct s_game		t_game;

// ===========================================
// ================= INIT ====================
// ===========================================

//  init_structs.c
t_parser	*init_struct_parser(void);

//  print_structs.c
void		print_parser_struct(t_parser *parser);
void		print_map_2d(char **matrix);

#endif
