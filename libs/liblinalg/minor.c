/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:31:40 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 00:56:06 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

double	minor(t_matrix *m, int i, int j, t_garbage_collector *gc)
{
	return (determinant_3x3(submatrix(m, i, j, gc)));
}
