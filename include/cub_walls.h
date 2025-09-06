/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_walls.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:21:04 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 19:18:31 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_WALLS_H
# define CUB_WALLS_H

typedef struct s_walls
{
	t_img			north;
	t_img			south;
	t_img			east;
	t_img			west;
}					t_walls;

#endif
