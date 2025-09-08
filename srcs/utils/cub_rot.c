/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:32:39 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 19:58:50 by  yaramire        ###   ########.fr       */
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
