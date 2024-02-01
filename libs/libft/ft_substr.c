/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:46:57 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 21:28:17 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*substr_start;
	char	*str_end;
	size_t	to_be_copied;

	if (s == NULL)
		return (NULL);
	str_end = (char *) s + ft_strlen(s);
	substr_start = (char *) s + start;
	if (substr_start >= str_end)
		return (ft_strdup(""));
	if (len <= ft_strlen(s) - start)
		to_be_copied = len + 1;
	else
		to_be_copied = str_end - substr_start + 1;
	if (to_be_copied == 0)
		return (NULL);
	substr = malloc(to_be_copied);
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, substr_start, to_be_copied - 1);
	substr[to_be_copied - 1] = '\0';
	return (substr);
}
