/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor_render.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:19:51 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 18:58:58 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FLOOR_RENDER_H
# define CUB_FLOOR_RENDER_H

# include "../utils/cub_vec.h"
# include "../utils/cub_rot.h"

typedef struct s_floor_render
{
	t_rot			start;
	t_rot			end;
	t_vecd			s;
	t_vecd			step;
	t_vecd			start_pos;
	t_vecd			tex;
	int				color;
	int				midpi;
	double			mid;
	double			row_len;
	double			dim;
	double			ang;
}					t_floor_render;

#endif
