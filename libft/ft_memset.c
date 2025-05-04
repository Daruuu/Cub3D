/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:16:26 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/10 03:57:54 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr_dest;	
	unsigned char	unsig_c;	

	i = 0;
	ptr_dest = (unsigned char *) dest;
	unsig_c = (unsigned char) c;
	while (i < len)
	{
		ptr_dest[i] = unsig_c;
		i++;
	}
	return ((void *) ptr_dest);
}
/*c es la variable por la que vamos a sustituir en (dest) tantas veces como (n)
tengamos
retornamos el puntero dest actualizado con los valores c (n veces)*/
