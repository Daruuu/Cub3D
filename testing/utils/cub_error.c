/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:44:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_error.h"
#include "cub_cleaner.h"

static void	puterr(char *string)
{
	write(1, string, stringlen(string));
}

void	handle_error(t_game *game, char *error, char *trace)
{
	int	mid;

	mid = (10 - stringlen(error)) / 2;
	puterr("\x1B[0m< \x1B[31mERROR\x1B[0m >\n");
	while (mid-- > 0)
		puterr(" ");
	puterr(error);
	if (trace)
	{
		puterr("\n");
		mid = (10 - stringlen(trace) - 2) / 2;
		while (mid-- > 0)
			puterr(" ");
		puterr("'");
		puterr(trace);
		puterr("'");
	}
	puterr("\n");
	clean_all(game);
	exit(0);
}

void	handle_warning(t_game *c, char *error)
{
	int	mid;

	(void)c;
	mid = (10 - stringlen(error)) / 2;
	puterr("<\x1B[1;33m WARNING \x1B[0m>\n");
	while (mid-- > 0)
		puterr(" ");
	puterr(error);
	puterr("\n");
}
