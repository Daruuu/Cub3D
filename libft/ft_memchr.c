/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:03:57 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/10 05:00:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc_s;
	unsigned char	c_tofind;
	size_t			i;

	uc_s = (unsigned char *) s;
	c_tofind = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (uc_s[i] == c_tofind)
			return ((void *)&uc_s[i]);
		i++;
	}
	return (NULL);
}
