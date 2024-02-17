/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:22:40 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:12:40 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

double	magnitude(t_vector *vector)
{
	return (pow(pow(vector->dim[0], 2) + pow(vector->dim[1], 2) + \
		pow(vector->dim[2], 2) + pow(vector->dim[3], 2), 0.5));
}
