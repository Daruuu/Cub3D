/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:22:09 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:22:09 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FILE_H
# define CUB_FILE_H

# include "../utils/cub_error.h"
# include "cub_parser.h"
# include "cub_map_parser.h"
# include "../cub3D.h"

int	load_f(char *filepath, t_vars *vars);

#endif
