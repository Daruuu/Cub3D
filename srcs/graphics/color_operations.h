/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 22:00:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_OPERATIONS_H
# define COLOR_OPERATIONS_H

# include <stdbool.h>
# include <stdlib.h>

// Color manipulation functions
int				color_add(int color, int current, float ratio);
int				color_dim(int color, float ratio);
int				blend_colors(int o, int n);

#endif
