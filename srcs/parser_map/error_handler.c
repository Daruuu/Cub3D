/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:49:01 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/07 10:49:35 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_error(char *str, int size, t_parser *map, t_game *game)
{
	(void) game;
	if (str && size > 0)
		write(2, str, size);
	if (map != NULL)
		free_parser_map(map);
	/*if (game != NULL)
		free_game(game);*/
	exit(EXIT_FAILURE);
}

void	handle_exit(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	write(2, str, size);
	exit(EXIT_FAILURE);
}
