#ifndef CALCULATIONS_H
#define CALCULATIONS_H

// t_vector vector_div(t_vector *first, t_vector second){
    
    
//     first[0] / second[0];
//     first[1] / second[1];
//     first[2 / second[2]];
//     return new;
// }

#include "Minirt.h"

t_vector    *scalar_division(t_vector *v, double scalar);
t_vector    *vector_difference(t_vector *v1, t_vector *v2);
t_vector    *vector_summ(t_vector *v1, t_vector *v2);
t_vector    *new_vector(double x, double y, double z);
double      modul( t_vector *v1);
double      vector_dot_product( t_vector *v1, t_vector *v2);
t_vector    *versor (t_vector *v);
t_vector    *scalar_multiplication(t_vector *v, double scalar);

#endif

// test comment
