/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:47:13 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/10 00:34:35 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*devuelve un puntero a la última ocurrencia del carácter c en la cadena s.
	o NULL si el carácter no se ha encontrado*/

char	*ft_strrchr(const char *s, int c)
{
	char	find_c;
	int		len_s;

	find_c = c;
	len_s = ft_strlen(s);
	while (len_s >= 0)
	{
		if (s[len_s] == find_c)
			return ((char *)&s[len_s]);
		len_s--;
	}
	return (NULL);
}
