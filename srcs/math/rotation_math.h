/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_math.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:48:18 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 23:11:55 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATION_MATH_H
# define ROTATION_MATH_H

# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_rot
{
	double	angle;
	double	cos;
	double	sin;
}				t_rot;

// Rotation utilities
t_rot			make_rot(double angle);

#endif
