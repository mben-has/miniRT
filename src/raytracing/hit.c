/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 07:19:45 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/06 07:20:18 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

void check_spheres(t_scene **scene, t_ray **ray, t_garbage_collector *gc)
{
    int h;
    double e;
      h = 0;
            while (h < (*scene)->nr_spheres)
            {
                e = hit_sphere((*scene)->spheres[h], (*ray), gc);
             
                if(e != -1.0)
                {   
                    if(!((*ray)->clo))
                        (*ray)->clo = init_clo('s', (void *)&((*scene)->spheres[h]), e, gc );
                    else if(((*ray)->clo) && (e < (*ray)->clo->distance))
                        (*ray)->clo = init_clo('s', (void *)&((*scene)->spheres[h]), e, gc );
                }
             
                h++;
            }
}

void check_cylinders(t_scene **scene, t_ray **ray, t_garbage_collector *gc)
{
     int h;
    double e;
      h = 0;
            while (h < (*scene)->nr_cylinders)
             {
                e = hit_cylinder((*scene)->cylinders[h], (*ray), gc);
             
                if(e != -1.0)
                {   
                    if(!((*ray)->clo))
                        (*ray)->clo = init_clo('c', (void *)&((*scene)->cylinders[h]), e, gc );
                    else if(((*ray)->clo) && (e < (*ray)->clo->distance))
                        (*ray)->clo = init_clo('c', (void *)&((*scene)->cylinders[h]), e, gc );
                }
             
                h++;
            }
}

void check_planes(t_scene **scene, t_ray **ray, t_garbage_collector *gc)
{
       int h;
    double e;
      h = 0;
           while (h < (*scene)->nr_planes)
             {
                e = hit_plane((*scene)->planes[h], (*ray), gc);
             
                if(e != -1.0)
                {   
                    if(!((*ray)->clo))
                        (*ray)->clo = init_clo('p', (void *)&((*scene)->planes[h]), e, gc );
                    else if(((*ray)->clo) && (e < (*ray)->clo->distance))
                        (*ray)->clo = init_clo('p', (void *)&((*scene)->planes[h]), e, gc );
                }
             
                h++;
            }
}

void check_hit(t_scene **scene, t_ray **ray, t_garbage_collector *gc)
{
     check_spheres(&(*scene), &(*ray), gc);
     check_cylinders(&(*scene), &(*ray), gc);
     check_planes(&(*scene), &(*ray), gc);      
}