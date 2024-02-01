/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:06:22 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 17:06:57 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_trim_char(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
At the end of the function begin stands on the first character
and end one character after the last character of the trimmed string.
If everything is trimmed or s1 is "", s1 and end are the same.
*/
static void	trim(char const **s1, char const **end, const char *set)
{
	while (*s1 < *end && is_trim_char(**s1, set))
		(*s1)++;
	while (*end > *s1 && is_trim_char(*(*end - 1), set))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*end;
	char		*trimmed_string;
	size_t		length;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = s1 + ft_strlen(s1);
	trim(&s1, &end, set);
	length = end - s1;
	trimmed_string = malloc(length + 1);
	if (trimmed_string == NULL)
		return (NULL);
	ft_strlcpy(trimmed_string, s1, length + 1);
	return (trimmed_string);
}
