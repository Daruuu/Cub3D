/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/08 17:16:28 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RAYCAST_STRUCT_H
# define CUB_RAYCAST_STRUCT_H

# include "../srcs/utils/cub_vec.h"
# include "../srcs/utils/cub_utils.h"
# include "cub_cardinal_enum.h"
# include "cub_portal_struct.h"

typedef struct s_ray
{
	t_vecd			st_cos;
	t_vecd			st_sin;
	double			ln_cos;
	double			ln_sin;
}					t_ray;

typedef struct s_trace
{
	t_ray			ray;
	t_ray			step;
	t_rot			rot;
	t_shape			line;
	t_vec			pos;
	t_vecd			ref;
	t_portal_render	*portal;
	t_cardinal		card;
	t_portal		*pt;
	int				i;
	double			newa;
	double			len;
	double			offset;
}					t_trace;

#endif
