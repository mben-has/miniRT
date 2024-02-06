// t_vector vector_div(t_vector *first, t_vector second){
    
    
//     first[0] / second[0];
//     first[1] / second[1];
//     first[2 / second[2]];
//     return new;
// }

#include "Calculation.h"


t_vector    *new_vector(double x, double y, double z){
    t_vector    *new;

    new = malloc(sizeof(t_vector));
        if(!new)
            return (NULL);
    new->coordinate[0] = x;
    new->coordinate[1] = y;
    new->coordinate[2] = z;
    return (new);
}


t_vector *scalar_division(t_vector *v, double scalar){
    int i = 0;
    t_vector    *new = new_vector(0,0,0);

    while(i < 3){
        new->coordinate[i] = v->coordinate[i] / scalar;
        i++;
    }
    return v;
}


t_vector *scalar_multiplication(t_vector *v, double scalar){
    int i = 0;
    t_vector    *new = new_vector(0,0,0);

    while(i < 3){
        new->coordinate[i] = v->coordinate[i] * scalar;
        i++;
    }
    return v;
}


t_vector    *vector_difference(t_vector *v1, t_vector *v2){
    t_vector    *new;
    new = new_vector( v1->coordinate[0] - v2->coordinate[0], \
                     v1->coordinate[1] - v2->coordinate[1], \
                     v1->coordinate[2] - v2->coordinate[2] );
    return new;
}


double  vector_dot_product( t_vector *v1, t_vector *v2){
    double dotProduct;

    dotProduct =   ( v1->coordinate[0] * v2->coordinate[0] + \
                     v1->coordinate[1] * v2->coordinate[1] + \
                     v1->coordinate[2] * v2->coordinate[2] );
    return dotProduct;
}


t_vector    *vector_summ(t_vector *v1, t_vector *v2){
    t_vector    *new;
    new = new_vector( v1->coordinate[0] + v2->coordinate[0], \
                     v1->coordinate[1] + v2->coordinate[1], \
                     v1->coordinate[2] + v2->coordinate[2] );
    return new;
}

double  modul( t_vector *v1){
    return(vector_dot_product(v1, v1));
}

t_vector    *versor (t_vector *v){
    t_vector    *new;
    double     lenght;

    lenght = sqrt(modul(v));
    new = new_vector((v->coordinate[0])/lenght, (v->coordinate[1])/lenght, (v->coordinate[2])/lenght);
    return      new;
}
