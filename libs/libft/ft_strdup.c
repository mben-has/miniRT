/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:57:28 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 14:20:09 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	i;
	char	*str_dup;

	length = ft_strlen(s) + 1;
	str_dup = (char *) malloc(length);
	if (str_dup == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str_dup[i] = s[i];
		i++;
	}
	return (str_dup);
}
