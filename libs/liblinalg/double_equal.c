/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:16:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:13:41 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

int	double_equal(double a, double b)
{
	return ((int)(fabs(a - b) < EPSILON));
}
