/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 21:49:48 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "audio_system.h"

void	init_sound_empty(t_sounds *sounds)
{
	sounds->door = 0;
	sounds->hurt = 0;
	sounds->stomp = 0;
	sounds->portal = 0;
	sounds->heal = 0;
	sounds->ambient = 0;
	sounds->walk = 0;
}

void	clear_sounds(t_sounds *sounds)
{
	(void)sounds;
}

bool	load_sound(uint32_t *s, char *path)
{
	(void)s;
	(void)path;
	return (false);
}

void	play_sound_alt(uint32_t s, bool play, bool loop)
{
	(void)s;
	(void)play;
	(void)loop;
}

void	play_sound(uint32_t s)
{
	(void)s;
}
