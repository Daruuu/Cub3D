/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdelay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:36:55 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 18:57:18 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <stdlib.h>

int	get_delay(bool startnow, int min, bool mac)
{
	static struct timeval	start;
	static struct timeval	stop;
	unsigned long			delta_us;

	if (startnow)
	{
		gettimeofday(&start, NULL);
		return (0);
	}
	else
		gettimeofday(&stop, NULL);
	delta_us = (stop.tv_sec - start.tv_sec) * 1000000
		+ stop.tv_usec - start.tv_usec;
	if (delta_us < (unsigned long)min)
	{
		if (!mac)
			usleep((min - delta_us) % 1000000);
		return (0);
	}
	return (delta_us - min);
}
