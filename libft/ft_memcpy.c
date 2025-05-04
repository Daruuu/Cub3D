/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 01:01:34 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/10 04:02:24 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ch_dst;
	char	*ch_src;

	ch_dst = (char *) dst;
	ch_src = (char *) src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		i++;
	}
	return ((void *)ch_dst);
}
