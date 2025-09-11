/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_system.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:16:42 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 21:49:19 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_SYSTEM_H
# define AUDIO_SYSTEM_H

# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_sounds
{
	uint32_t	door;
	uint32_t	hurt;
	uint32_t	stomp;
	uint32_t	portal;
	uint32_t	heal;
	uint32_t	ambient;
	uint32_t	walk;
}				t_sounds;

void			init_sound_empty(t_sounds *sounds);
void			clear_sounds(t_sounds *sounds);
bool			load_sound(uint32_t *s, char *path);
void			play_sound(uint32_t s);
void			play_sound_alt(uint32_t s, bool play, bool loop);

#endif
