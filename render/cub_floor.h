/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:26:48 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:26:48 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FLOOR_H
# define CUB_FLOOR_H

# include "../cub.h"

void	setup_floor(t_vars *vars, t_floor_render *f);
void	draw_floor(t_vars *vars);
void	render_row_floor(t_vars *vars, t_floor_render *f);

#endif
