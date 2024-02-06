/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:20:46 by marschul          #+#    #+#             */
/*   Updated: 2024/02/06 19:44:56 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*vector_add(t_vector a, t_vector b)
{
	t_vector	*result;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	*result[0] = a[0] + b[0];
	*result[1] = a[1] + b[1];
	*result[2] = a[2] + b[2];
	*result[3] = a[3] + b[3];
	return (result);
}
