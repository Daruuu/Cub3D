/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bitmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:26:18 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:26:18 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BITMAP_H
# define CUB_BITMAP_H

# include "../cub.h"

t_bmp_partial_alligned_header	get_generic_header(int width, int height);
void							*bad_bzero(void *o, size_t len);
int								render_and_save(t_vars *vars);

#endif
