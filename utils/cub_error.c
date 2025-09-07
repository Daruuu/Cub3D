/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:30:39 by yamir             #+#    #+#             */
/*   Updated: 2025/09/07 18:36:19 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_error.h"

static void	puterr(char *string)
{
	write(1, string, stringlen(string));
}

void	handle_error(t_vars *vars, char *error, char *trace)
{
	int	mid;

	mid = (10 - stringlen(error)) / 2;
	puterr("Error\n");
	// puterr("\x1B[0m< \x1B[31mERROR\x1B[0m >\n");
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
	clean_all(vars);
	exit(0);
}

void	handle_warning(t_vars *c, char *error)
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
