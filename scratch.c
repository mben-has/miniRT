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