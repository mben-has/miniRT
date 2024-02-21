void    ft_init_camera(t_camera *cam)
{
    double width;
    if (cam->fov == 180.0f)
        cam->fov = 179.999f;
    width = (cam->fov / 2.0f) * M_PI / 180;
    width = tan(width);
    if (cam->cam.normalized.e[0] == 0.0f
        && (cam->cam.normalized.e[1] == 1.0f || cam->cam.normalized.e[1] == -1.0f)
        && cam->cam.normalized.e[2] == 0.0f)
        {
            cam->up = (t_vec3){0.0f, 0.0f, -1.0f};
        }
    else
        cam->up = (t_vec3){0.0f, 1.0f, 0.0f};
    cam->right = vec3_scalar_multiply(vec3_normalize(vec3_cross(cam->up, cam->cam.normalized)), width);
    cam->up = vec3_scalar_multiply(vec3_normalize(vec3_cross(cam->cam.normalized, cam->right)), width / 2);
}

//plane
double		x_angle;
	double		z_angle;
	t_vector *pl_normal = vector(plane_parsing->normal_vector->coordinate[0], plane_parsing->normal_vector->coordinate[1],plane_parsing->normal_vector->coordinate[2],gc);
	calculate_rotation_angles(pl_normal, &x_angle, &z_angle);
	t_matrix *rz = rotation_z(z_angle, gc);
	t_matrix *rx = rotation_x(x_angle, gc);
	m2 = matrix_mult_m(rz, rx, gc);


    / t_matrix	*set_matrix_plane_2(t_plane_p *plane_parsing, t_camera_p camera_parsing, t_garbage_collector *gc)
// {
// 	t_matrix	*m1;
// 	t_matrix	*m2;
// 	t_matrix	*m3;
// 	t_matrix	*result;
// 	t_vector	*v;
// 	double		angle;
// 	double		dot_product;
// 	t_vector	*cam_point;

// 	v = vector_cast(plane_parsing->point, gc);
// 	m1 = translation(v, gc);

// 	//check if plane normal vector is perpendicular to cam orientation
// 	if(dot(camera_parsing.orientation , plane_parsing->normal_vector) == 0)
// 	{
// 		return(m1);
		
// 	}
// 	// create vector from camera point to plane point
// 	cam_point = vector(plane_parsing->point->coordinate[0] - camera_parsing.point->coordinate[0],
// 						plane_parsing->point->coordinate[1] - camera_parsing.point->coordinate[1],
// 						plane_parsing->point->coordinate[2] - camera_parsing.point->coordinate[2],
// 										 gc);
// 	//invert the normal vector of plane depending if the is above or under the light
// 	if(dot(cam_point , plane_parsing->normal_vector) > 0)
// 	{
// 		for (int i = 0; i < 3; i++) 
//         	plane_parsing->normal_vector->coordinate[i] = -(plane_parsing->normal_vector->coordinate[i]);
		
// 	}
// 	dot_product = dot(vector_cast(plane_parsing->normal_vector, gc), vector(0, 1, 0, gc));
// 	angle = acos(dot_product);
// 	// printf("%f\n", angle);
// 	m2 = rotation_x(-angle, gc);
// 	// m3 = rotation_z(angle, gc);
// 	result = matrix_mult_m(m1, m2, gc);
// 	// result = matrix_mult_m(m3, result, gc);
// 	return (result);
// }

// if (ray->direction->dim[0] == 0 && ray->direction->dim[1] == 0)
			// {
			// 	xs= intersect_world(world, ray, gc);
			// 	ht = hit(xs, ray->original_length);
			// 	if (ht.object != NULL)
			// 	{
			// 		printf("ray.direction = (%f, %f, %f) \n",
							ray->direction->dim[0], ray->direction->dim[1],
							ray->direction->dim[2]);
			// 		printf("ray.origin = (%f, %f, %f) \n", ray->origin->dim[0],
							ray->origin->dim[1], ray->origin->dim[2]);
			// 		printf("ray.lenght = %f \n", ray->original_length);
			// 		printf("hit = %f\n", ht.t);
			// 		mlx_put_pixel(img, i, j, 0xFF0000FF);
			// 		return ;
			// 	}
			// }

    //         t_intersections	xs;
	// t_intersection	ht;

		// check if plane normal vector is perpendicular to cam orientation
	// if(dot(camera_parsing.orientation , plane_parsing->normal_vector) == 0)
	// {
	// 	return(m1);
		
	// }
	// // create vector from camera point to plane point
	// cam_point = vector(plane_parsing->point->coordinate[0] - camera_parsing.point->coordinate[0],
	// 					plane_parsing->point->coordinate[1] - camera_parsing.point->coordinate[1],
	// 					plane_parsing->point->coordinate[2] - camera_parsing.point->coordinate[2],
	// 									 gc);
	// // }

	// //invert the normal vector of plane depending if the is above or under the light
	// if(dot(cam_point , plane_parsing->normal_vector) == 0)
	// {
	// 	return(m1);
		
	// }
		xs= intersect_world(world, ray, gc);
				ht = hit(xs, ray->original_length);
				// if(ray->direction->dim[0] == 0 && ray->direction->dim[2] == 0)
				// {
				// 	printf("xs[0] = %f\n", xs.xs[0]);
				// 	printf("xs[1] = %f\n", xs.xs[1]);
				// 	printf("ray length = %f\n", ray->original_length);
					
				// 	if (ht.object != NULL)
				// 	{
				// 		printf("ray.direction = (%f, %f, %f) \n",
				// 				ray->direction->dim[0], ray->direction->dim[1],
				// 				ray->direction->dim[2]);
				// 		printf("ray.origin = (%f, %f, %f) \n", ray->origin->dim[0],
				// 				ray->origin->dim[1], ray->origin->dim[2]);
				// 		// printf("ray.lenght = %f \n", ray->original_length);
				// 		printf("hit = %f\n", ht.t);
				// 		mlx_put_pixel(*img, i, j, 0xFF0000FF);
				// 	}
				// 	// exit(1);
				// }

           t_intersections	xs;
	t_intersection	ht;
	