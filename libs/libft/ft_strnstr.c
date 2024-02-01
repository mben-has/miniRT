/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:59:40 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 19:31:48 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_length;
	size_t	i;
	size_t	j;

	needle_length = ft_strlen(needle);
	if (needle_length == 0)
		return ((char *) haystack);
	if (needle_length > min(ft_strlen(haystack), len))
		return (NULL);
	i = 0;
	while (i < min(ft_strlen(haystack), len) - needle_length + 1)
	{
		j = 0;
		while (j < needle_length)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (j == needle_length)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
