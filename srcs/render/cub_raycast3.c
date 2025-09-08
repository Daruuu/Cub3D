/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:27:56 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:27:56 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_raycast.h"

/*
** Casts the main ray forward, by adding the cos/sin steps alternately based
** on which is the closest
*/

void	cast_forward(t_ray *ray, t_ray step)
{
	if (ray->ln_cos < ray->ln_sin)
	{
		ray->st_cos.x += step.st_cos.x;
		ray->st_cos.y += step.st_cos.y;
		ray->ln_cos += step.ln_cos;
	}
	else
	{
		ray->st_sin.x += step.st_sin.x;
		ray->st_sin.y += step.st_sin.y;
		ray->ln_sin += step.ln_sin;
	}
}
