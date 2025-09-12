/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 21:46:33 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_main.h"
#include "parser_setter.h"
#include "../file_loader/string_utils.h"

char	*read_arg(char *s1, char *s2, char **ret)
{
	while (*s1 && *s2)
	{
		if (*s2 == ' ')
		{
			s2++;
			continue ;
		}
		if (*s1 != *s2)
			return (0);
		s2++;
		s1++;
	}
	if (*s1 == 0 && *s2 == ' ')
	{
		while (*s2 == ' ')
			s2++;
		truncate_str(s2);
		*ret = s2;
		return (s2);
	}
	return (0);
}

bool	read_argument_sounds(t_game *game, t_line *file)
{
	char	*arg;

	if (read_arg("S_DOOR", file->line, &arg))
		set_sound(&(game->sounds.door), game, arg);
	else if (read_arg("S_HURT", file->line, &arg))
		set_sound(&(game->sounds.hurt), game, arg);
	else if (read_arg("S_STOMP", file->line, &arg))
		set_sound(&(game->sounds.stomp), game, arg);
	else if (read_arg("S_PORTAL", file->line, &arg))
		set_sound(&(game->sounds.portal), game, arg);
	else if (read_arg("S_HEAL", file->line, &arg))
		set_sound(&(game->sounds.heal), game, arg);
	else if (read_arg("S_AMBIENT", file->line, &arg))
		set_sound(&(game->sounds.ambient), game, arg);
	else if (read_arg("S_WALK", file->line, &arg))
		set_sound(&(game->sounds.walk), game, arg);
	else
		return (false);
	return (true);
}

bool	read_argument_custom(t_game *game, t_line *file)
{
	char	*arg;

	if (read_arg("FLOOR", file->line, &arg))
		set_texture(&(game->floor), game, arg);
	else if (read_arg("GOOMBA", file->line, &arg))
		set_texture(&(game->goomba_img), game, arg);
	else if (read_arg("PORTAL", file->line, &arg))
		set_texture(&(game->portal), game, arg);
	else if (read_arg("DOOR", file->line, &arg))
		set_texture(&(game->door_img), game, arg);
	else if (read_arg("HK", file->line, &arg))
		set_texture(&(game->health_img), game, arg);
	else if (read_arg("SKYBOX", file->line, &arg)
		&& game->resx > 0 && game->resy > 0)
		make_skybox(game, &(game->skybox), arg);
	else if (read_arg("GUN", file->line, &arg))
		make_gun(game, &(game->gun), arg);
	else if (read_arg("DASH", file->line, &arg))
		make_dash(game, &(game->dash), arg);
	else
		return (read_argument_sounds(game, file));
	return (true);
}

bool	read_argument(t_game *game, t_line *file)
{
	char	*arg;

	if (read_arg("R", file->line, &arg))
		set_resolution(game, arg);
	else if (read_arg("S", file->line, &arg))
		set_texture(&(game->sprite_img), game, arg);
	else if (read_arg("NO", file->line, &arg))
		set_texture(&(game->walls.north), game, arg);
	else if (read_arg("SO", file->line, &arg))
		set_texture(&(game->walls.south), game, arg);
	else if (read_arg("WE", file->line, &arg))
		set_texture(&(game->walls.west), game, arg);
	else if (read_arg("EA", file->line, &arg))
		set_texture(&(game->walls.east), game, arg);
	else if (read_arg("F", file->line, &arg))
		set_color(game, &(game->bottom_color), arg);
	else if (read_arg("C", file->line, &arg))
		set_color(game, &(game->top_color), arg);
	else if (game->bonus)
		return (read_argument_custom(game, file));
	else
		return (false);
	return (true);
}
