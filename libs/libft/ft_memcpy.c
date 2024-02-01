/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:29:22 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 21:39:20 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Precondition: The memory areas must not overlap
*  It lies in the responibility of the user to pass valid pointers.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointer;

	if (dest == NULL && src == 0)
		return (NULL);
	pointer = (unsigned char *) dest;
	while (n > 0)
	{
		*pointer = *(const unsigned char *) src;
		src++;
		pointer++;
		n--;
	}
	return (dest);
}
