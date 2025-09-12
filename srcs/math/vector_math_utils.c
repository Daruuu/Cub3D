/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:35:02 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 23:37:48 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

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

double	calc_sqrtlen(t_vecd v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

double	distance(t_vecd v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}
