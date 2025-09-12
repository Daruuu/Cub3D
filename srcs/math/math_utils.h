/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 12:54:40 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

// ===================== ANGULAR CALCULATIONS ===================== //
double			calculate_angular_distance(double angle_a, double angle_b);

// ===================== VALUE MANIPULATION ===================== //
void			swap_double_values(double *value_a, double *value_b);

// ===================== FRACTIONAL OPERATIONS ===================== //
double			normalize_fractional_part(double value);

// ===================== INTERPOLATION FUNCTIONS ===================== //
double			smooth_ease_in_out_interpolation(double t);

#endif
