/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:06:08 by marschul          #+#    #+#             */
/*   Updated: 2023/06/27 11:49:16 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check_for_overflow(size_t a, size_t b)
{
	return (a + b < a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length1;
	size_t	length2;
	size_t	length_all;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	if (check_for_overflow(length1, length2) \
		|| check_for_overflow(length1 + length2, 1))
		return (NULL);
	else
		length_all = length1 + length2 + 1;
	new = (char *) malloc(length_all);
	if (new == NULL)
		return (NULL);
	ft_memcpy((void *) new, (const void *) s1, length1);
	ft_memcpy((void *) new + length1, (const void *) s2, length2);
	new[length_all - 1] = '\0';
	return (new);
}
