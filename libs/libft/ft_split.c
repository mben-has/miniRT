/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:05:23 by marschul          #+#    #+#             */
/*   Updated: 2023/10/10 12:08:17 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_wordbegin(char const *s, size_t i, char c)
{
	return ((i == 0 || s[i - 1] == c) && s[i] != c);
}

static int	is_wordend(char const *s, size_t i, char c)
{
	return (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c));
}

static char	**create_array(const char *s, char c)
{
	size_t	words;
	size_t	i;
	char	**array;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (is_wordbegin(s, i, c))
			words++;
		i++;
	}
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	else
	{
		array[words] = NULL;
		return (array);
	}
}

static void	*free_array(char **array, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	start;
	size_t	current_word;
	size_t	i;

	array = create_array(s, c);
	current_word = 0;
	i = 0;
	while (array != NULL && s[i] != '\0')
	{
		if (is_wordbegin(s, i, c))
			start = i;
		if (is_wordend(s, i, c))
		{
			array[current_word] = malloc(i - start + 2);
			if (array[current_word] == NULL)
				return (free_array(array, current_word));
			ft_strlcpy(array[current_word], s + start, i - start + 2);
			current_word++;
		}
		i++;
	}
	return (array);
}
