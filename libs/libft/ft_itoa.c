/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:25:07 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 20:04:28 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	dimension(long int n)
{
	int	dim;

	dim = 1;
	while (n >= 10)
	{
		n = n / 10;
		dim = dim * 10;
	}
	return (dim);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	char		str[12];
	char		*result;
	int			i;
	int			dim;

	nbr = (long int) n;
	ft_bzero(str, 12);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr = -nbr;
	}
	dim = dimension(nbr);
	while (dim != 0)
	{
		str[i++] = '0' + ((nbr / dim) % 10);
		dim = dim / 10;
	}
	result = ft_strdup(str);
	return (result);
}
