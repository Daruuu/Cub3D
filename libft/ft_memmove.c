/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 03:10:11 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/10 03:36:58 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	c_dst = (char *)dst;
	c_src = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (c_dst > c_src)
	{
		while (len--)
			c_dst[len] = c_src[len];
	}
	else if (c_dst < c_src)
	{
		while (len--)
			*c_dst++ = *c_src++;
	}
	return (dst);
}
