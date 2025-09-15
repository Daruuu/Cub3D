/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_setter.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 19:52:12 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_SETTER_H
# define PARSER_SETTER_H

# include "../cub3D.h"

void	set_resolution(t_game *game, char *input);
void	set_texture(t_img *img, t_game *game, char *path);
void	set_color(t_game *game, int *val, char *input);
void	set_sound(uint32_t *s, t_game *game, char *path);

#endif
