/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:34:24 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:34:24 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CARDINAL_H
# define CUB_CARDINAL_H

# include "../render/cub_raycast.h"

t_cardinal	get_cardinal(t_trace trace);
t_cardinal	get_opposite(t_cardinal card);
t_vec		get_direction(t_cardinal card);

#endif
