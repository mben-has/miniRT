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