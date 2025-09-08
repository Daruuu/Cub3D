/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:28:44 by dasalaza         ###   ########.fr       */
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
