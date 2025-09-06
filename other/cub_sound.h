/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sound.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:21:54 by yamir             #+#    #+#             */
/*   Updated: 2025/06/01 19:35:11 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SOUND_H
# define CUB_SOUND_H

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
