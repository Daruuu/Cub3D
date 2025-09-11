/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 15:28:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_FILE_LOADER_H
# define PARSER_FILE_LOADER_H

# include "../utils/cub_error.h"
# include "parser_main.h"
# include "parser_map_parser.h"
# include "../cub3D.h"

int	load_f(char *filepath, t_game *game);

#endif
