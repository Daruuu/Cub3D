/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_primitives.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 00:52:41 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_PRIMITIVES_H
# define RENDERING_PRIMITIVES_H

# include "color_operations.h"
# include "image_operations.h"

// Strip rendering functions
void			set_strip(t_img *data, t_shape shape, int color);
void			set_img_strip(t_img *data, t_shape shape, float offset);
void			set_portal_strip(t_img *d, t_shape shape, t_img *tex, float offset);
void			e_portal_strip(t_img *data, t_shape shape, t_img *tex, float offset);

// Shape rendering functions
void			rect(t_img *data, t_shape shape, int color);

#endif
