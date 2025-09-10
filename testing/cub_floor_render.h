/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor_render.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/08 17:15:47 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FLOOR_RENDER_H
# define CUB_FLOOR_RENDER_H

# include "../srcs/utils/cub_vec.h"
# include "../srcs/utils/cub_rot.h"

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
