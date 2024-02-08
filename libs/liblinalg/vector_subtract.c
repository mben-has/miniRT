/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_subtract.c                                  :+:      :+:    :+:   */
/*                                                    +- +-         +-     */
/*   By: marschul <marschul@student.42.fr>          +-  +-       +-        */
/*                                                +#+#+#+#+-   +-           */
/*   Created: 2024/02/07 16:46:08 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 19:32:47 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*vector_subtract(t_vector *a, t_vector *b)
{
	t_vector	*result;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	result->dim[0] = a->dim[0]- b->dim[0];
	result->dim[1] = a->dim[1]- b->dim[1];
	result->dim[2] = a->dim[2]- b->dim[2];
	result->dim[3] = a->dim[3]- b->dim[3];
	return (result);
}