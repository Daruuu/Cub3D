/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rot.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:32:45 by yamir             #+#    #+#             */
/*   Updated: 2025/06/01 19:39:11 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ROT_H
# define CUB_ROT_H

# include <math.h>

typedef struct s_rot
{
	double		angle;
	double		cos;
	double		sin;
}				t_rot;

t_rot			make_rot(double angle);

#endif
