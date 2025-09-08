/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 01:07:06 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CARDINAL_H
# define CUB_CARDINAL_H

# include "../render/cub_raycast.h"

t_cardinal	get_cardinal(t_trace trace);
t_cardinal	get_opposite(t_cardinal card);
t_vec		get_direction(t_cardinal card);

#endif
