/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouseover_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:20:12 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 18:59:34 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MOUSEOVER_STRUCT_H
# define CUB_MOUSEOVER_STRUCT_H

typedef struct s_mouseover
{
	bool			found;
	t_vec			pos;
	t_cardinal		card;
}					t_mouseover;

#endif
