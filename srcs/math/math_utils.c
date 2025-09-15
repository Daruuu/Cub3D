/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:48:05 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 12:55:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include <math.h>

/**
 * Calculates the shortest angular distance between two angles.
 * Returns a value in the range [-π, π] representing the shortest path
 * from angle_a to angle_b.
 * 
 * @param angle_a First angle in radians
 * @param angle_b Second angle in radians
 * @return Angular distance in radians
 */
double	calc_angular_distance(double angle_a, double angle_b)
{
	return (atan2(sin(angle_a - angle_b), cos(angle_a - angle_b)));
}

/**
 * Swaps the values of two double variables.
 * 
 * @param value_a Pointer to first double value
 * @param value_b Pointer to second double value
 */
void	swap_double_values(double *value_a, double *value_b)
{
	double	temp;

	temp = *value_a;
	*value_a = *value_b;
	*value_b = temp;
}

/**
 * Normalizes the fractional part of a number to the range [0, 1).
 * Handles negative numbers by wrapping them to positive values.
 * Used for texture coordinate mapping and periodic functions.
 * 
 * @param value The input value
 * @return Normalized fractional part in range [0, 1)
 */
double	normalz_fractional_part(double value)
{
	double	fractional_part;

	fractional_part = fmod(value, 1);
	if (value < 0)
		return (1 - fabs(fractional_part));
	return (fractional_part);
}

/**
 * Smooth ease-in-out interpolation function.
 * Provides smooth acceleration and deceleration for animations.
 * Input range: [0, 1], Output range: [0, 1]
 * 
 * @param t Interpolation parameter (0.0 to 1.0)
 * @return Smoothed interpolation value
 */
double	smooth_ease_in_out_interpolation(double t)
{
	float	squared_t;

	squared_t = t * t;
	return (squared_t / (2.0f * (squared_t - t) + 1.0f));
}
