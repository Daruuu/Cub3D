/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 23:38:24 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

double	distancemid2(t_vecd start, t_vecd end)
{
	end.x -= start.x + 0.5;
	end.y -= start.y + 0.5;
	return (sqrt(end.x * end.x + end.y * end.y));
}

double	square_dist(t_vec3d start, t_vecd end)
{
	end.x -= start.x;
	end.y -= start.y;
	return (end.x * end.x + end.y * end.y);
}

double	square_dist_mid(t_vec3d start, t_vecd end)
{
	end.x -= start.x - 0.5;
	end.y -= start.y - 0.5;
	return (end.x * end.x + end.y * end.y);
}

int	square_dist2i(t_vec start, t_vec end)
{
	end.x -= start.x;
	end.y -= start.y;
	return (end.x * end.x + end.y * end.y);
}

int	dist2di(t_vecd start, t_vec end)
{
	start.x -= end.x + 0.5;
	start.y -= end.y + 0.5;
	return (sqrt(start.x * start.x + start.y * start.y));
}
