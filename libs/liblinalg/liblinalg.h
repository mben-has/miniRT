/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblinalg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:19:25 by marschul          #+#    #+#             */
/*   Updated: 2024/02/06 19:33:44 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLINALG_H
# define LIBLINALG_H

# include <stdlib.h>

typedef	double t_vector[4];

typedef	double t_matrix[4][4];

typedef double t_color[3];

t_vector	*vector_add(t_vector a, t_vector b);

#endif
