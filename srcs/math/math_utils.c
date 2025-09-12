/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:48:05 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 23:32:23 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include <math.h>

double	get_angdist(double a, double b)
{
	return (atan2(sin(a - b), cos(a - b)));
}

void	swap_d(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

double	modabs(double d)
{
	double	a;

	a = fmod(d, 1);
	if (d < 0)
		return (1 - fabs(a));
	return (a);
}

double	ease_in_out(double t)
{
	float	sqt;

	sqt = t * t;
	return (sqt / (2.0f * (sqt - t) + 1.0f));
}
