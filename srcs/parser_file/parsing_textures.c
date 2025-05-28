/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:18:16 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/28 19:18:18 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
int	check_textures_and_colors(t_parser *parser)
{
	if (!parser)
		return (1);
	if (!parser->north || !parser->south || !parser->east \
			|| !parser->west || !parser->floor || !parser->ceiling)
		return (1);
	return (0);
}
*/

int	check_textures_and_colors(t_parser *parser)
{
	if (!parser->north)
		return (printf(ERROR_INVALID_NORTH_TEXTURE), 1);
	if (!parser->south)
		return (printf(ERROR_INVALID_SOUTH_TEXTURE), 1);
	if (!parser->east)
		return (printf(ERROR_INVALID_EAST_TEXTURE), 1);
	if (!parser->west)
		return (printf(ERROR_INVALID_WEST_TEXTURE), 1);
	if (!parser->floor)
		return (printf(ERROR_INVALID_FLOOR_TEXTURE), 1);
	if (!parser->ceiling)
		return (printf(ERROR_INVALID_CEILING_TEXTURE), 1);
	return (0);
}
