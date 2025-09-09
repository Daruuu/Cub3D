/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdelay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 14:13:54 by dasalaza         ###   ########.fr       */
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
