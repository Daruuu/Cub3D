/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:35:02 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 13:10:09 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

/* Vector normalization and length calculations
*/
void	normalize(t_vecd *vec, double scale)
{
	double	len;

	len = sqrt(vec->x * vec->x + vec->y * vec->y);
	if (len < 0.0001)
	{
		vec->x = 0;
		vec->y = 0;
		return ;
	}
	vec->x /= len;
	vec->y /= len;
	vec->x *= scale;
	vec->y *= scale;
}

int	dist2di(t_vecd start, t_vec end)
{
	start.x -= end.x + 0.5;
	start.y -= end.y + 0.5;
	return (sqrt(start.x * start.x + start.y * start.y));
}

double	distance(t_vecd v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

double	distancemid2(t_vecd start, t_vecd end)
{
	end.x -= start.x + 0.5;
	end.y -= start.y + 0.5;
	return (sqrt(end.x * end.x + end.y * end.y));
}
