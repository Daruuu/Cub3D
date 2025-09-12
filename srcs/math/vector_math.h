/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 13:11:47 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MATH_H
# define VECTOR_MATH_H

# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_vec
{
	int	x;
	int	y;
}				t_vec;

typedef struct s_vecd
{
	double	x;
	double	y;
}				t_vecd;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

// Vector normalization and length calculations
double			calc_sqrtlen(t_vecd v);
int				square_dist2i(t_vec start, t_vec end);
double			square_dist(t_vec3d start, t_vecd end);
double			square_dist_mid(t_vec3d start, t_vecd end);

// Distance calculations
void			normalize(t_vecd *vec, double scale);
int				dist2di(t_vecd start, t_vec end);
double			distance(t_vecd v);
double			distancemid2(t_vecd start, t_vecd end);

#endif
