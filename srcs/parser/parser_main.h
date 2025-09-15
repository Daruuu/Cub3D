/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 15:32:18 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MAIN_H
# define PARSER_MAIN_H

# include "../cub3D.h"
# include "../render/render_textures.h"

bool	read_argument_sounds(t_game *game, t_line *file);
bool	read_argument_custom(t_game *game, t_line *file);
bool	read_argument(t_game *game, t_line *file);

#endif
