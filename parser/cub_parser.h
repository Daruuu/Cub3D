/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:22:54 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:22:54 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSER_H
# define CUB_PARSER_H

# include "../cub.h"
# include "cub_setter.h"
# include "../render/cub_texture.h"

bool	read_argument_sounds(t_vars *vars, t_line *file);
bool	read_argument_custom(t_vars *vars, t_line *file);
bool	read_argument(t_vars *vars, t_line *file);

#endif
