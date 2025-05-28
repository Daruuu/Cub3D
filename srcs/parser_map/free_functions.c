/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:47:48 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/28 19:23:46 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_parser_map(t_parser *parser)
{
	int	i;

	i = 0;
	if (parser != NULL && parser->map != NULL)
	{
		while (parser->map[i] != NULL)
		{
			free(parser->map[i]);
			i++;
		}
		free(parser->map);
	}
	parser->map = NULL;
}

void	free_matrix(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_parser_struct(t_parser *parser)
{
	if (!parser)
		return ;
	if (parser->file_map)
		free_matrix(parser->file_map);
	if (parser->map)
		free_matrix(parser->map);
	if (parser->north != NULL)
		free(parser->north);
	if (parser->south != NULL)
		free(parser->south);
	if (parser->west != NULL)
		free(parser->west);
	if (parser->east != NULL)
		free(parser->east);
	if (parser->floor != NULL)
		free(parser->floor);
	if (parser->ceiling != NULL)
		free(parser->ceiling);
	free(parser);
}
