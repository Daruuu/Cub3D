/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:46:59 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_rot.h"

t_rot	make_rot(double angle)
{
	t_rot	rot;

	rot.angle = angle;
	rot.cos = cos(rot.angle);
	rot.sin = sin(rot.angle);
	return (rot);
}
