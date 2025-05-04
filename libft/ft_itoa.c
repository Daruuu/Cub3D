/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:34:30 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/16 13:36:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_number(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n == -0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n = n * -1;
		len = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*array;
	long	ln;
	int		size_nbr;

	size_nbr = ft_len_number(n);
	ln = n;
	if (ln < 0)
		ln *= -1;
	array = malloc(sizeof(char) * (size_nbr + 1));
	if (!array)
		return (NULL);
	array[size_nbr] = '\0';
	size_nbr--;
	while (ln > 0)
	{
		array[size_nbr] = (ln % 10) + '0';
		ln /= 10;
		size_nbr--;
	}
	if (n < 0)
		array[0] = '-';
	else if (n == 0)
		array[0] = '0';
	return (array);
}
/*
int	main()
{
	char	*result;
	//int	n = 12345;
	//int	n = -623;
	int	n = 0;
	//int	n = -200;
	//int	n = -2147483648;
	//printf("%d\n", ft_len_number(n));
	result =  ft_itoa(n);
	//printf("%d\n", result);
	//printf("%s\n", result);
	int	i;

	i = 0;
	while (i < ft_len_number(n))
	{
		printf("%c", result[i]);
		i++;
	}
	return (0);
}
*/
