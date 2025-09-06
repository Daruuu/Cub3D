/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:20:32 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 19:14:06 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PORTAL_STRUCT_H
# define CUB_PORTAL_STRUCT_H

typedef struct s_portal_render
{
	t_shape					line;
	float					offset;
	struct s_portal_render	*next;
}							t_portal_render;

typedef struct s_portal
{
	t_vec					pos;
	t_cardinal				card;
	struct s_portal			*link;
}							t_portal;

#endif
