/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 06:53:14 by marschul          #+#    #+#             */
/*   Updated: 2023/06/18 18:24:06 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s);
	while (length > 0)
	{
		if (s[length] == (char) c)
			return ((char *) s + length);
		length--;
	}
	if (s[0] == (char) c)
		return ((char *) s);
	return (NULL);
}
