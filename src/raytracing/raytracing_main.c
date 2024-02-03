/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:49 by marschul          #+#    #+#             */
/*   Updated: 2024/02/03 01:38:46 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"
#include "Calculation.h"


#define WIDTH 500
#define HEIGHT 500
#define RATIO 16.0 / 9.0


typedef struct s_ray{
	t_vector* origin;
	t_vector* direction;
} t_ray;

// Is to get the value of X,Y,Z at a certain t;
// void *point_at( t_vector origin, t_vector direction)
// {
// 	// point3 at(double t) const {
//     //     return orig + t*dir;
//     // }
// }




// bool check_intersection(){
		
// }

t_ray *create_ray(t_vector *origin, t_vector *direction){
	t_ray *new; 
    new = malloc(sizeof(t_ray));
	new->direction = direction;
	new->origin = origin;
	return new;
}


// bool hit_sphere(const point3& center, double radius, const ray& r) {
//     vec3 oc = r.origin() - center;
//     auto a = dot(r.direction(), r.direction());
//     auto b = 2.0 * dot(oc, r.direction());
//     auto c = dot(oc, oc) - radius*radius;
//     auto discriminant = b*b - 4*a*c;
//     return (discriminant >= 0);
// }

typedef struct s_viewport{
	t_vector *view_u;
	t_vector *view_v;
	t_vector *delta_u;
	t_vector *delta_v;
	t_vector *center;
	t_vector *upper_left;
	t_vector *initial_location;
} t_viewport;


// t_viewport *setup(t_scene *scene){
// 	// double aspect_ratio = 16.0 / 9.0; 
//     int image_height = (int)(WIDTH/RATIO);
// 	if (image_height < 1){
// 			image_height = 1;
// 	}
	
//     // Camera

//     float focal_length = 1.0;
//     float viewport_height = 2.0;
//     float viewport_width = viewport_height * (double)(WIDTH)/image_height;

//     t_vector *viewport_u = new_vector(viewport_width, 0, 0);
//     t_vector *viewport_v = new_vector(0, -viewport_height, 0);
// 	// pixel conversion to delta step
//     t_vector *pixel_delta_u = scalar_division(viewport_u, WIDTH);
//     t_vector *pixel_delta_v = scalar_division(viewport_v , image_height);
// 	t_vector *vec3 = new_vector( 0, 0, focal_length);

//     // Calculate the location of the upper left pixel.
// 	//  (((origin - center) - vector_u) - vector_v')
//     t_vector *viewport_upper_left = vector_difference(
// 		vector_difference(vector_difference(&(scene->camera.point), vec3),scalar_division(viewport_u, 2))
// 									, scalar_division(viewport_v,2));
//     t_vector *pixel_initial_loc = vector_summ(viewport_upper_left, scalar_division(vector_summ(pixel_delta_u, pixel_delta_v), 2));
	
// 	// return the viewport
	
// }


t_vector *ray_color(t_ray *r) {
    t_vector *unit_direction = versor(r->direction);
    double a = (unit_direction->coordinate[1] + 1.0) / 2;
	t_vector *color1 = new_vector(1.0, 1.0, 1.0);
	t_vector *color2 = new_vector(0.5, 0.7, 1.0);
    return vector_summ(scalar_multiplication(color1,(1.0-a)), scalar_multiplication(color2,(a)));
}
unsigned int rgbToHex(t_vector *color) {
    int g = (int)(color->coordinate[1] * 255.0);
    int r = (int)(color->coordinate[0] * 255.0);
    int b = (int)(color->coordinate[2] * 255.0);

    // Ensure that the values are within the valid range [0, 255]
    r = (r < 0) ? 0 : ((r > 255) ? 255 : r);
    g = (g < 0) ? 0 : ((g > 255) ? 255 : g);
    b = (b < 0) ? 0 : ((b > 255) ? 255 : b);

    // Combine the RGB values into a single hexadecimal value
    return (r << 16) | (g << 8) | b;
}

int	raytracing(t_scene *scene)
{
	// Mohammed's part
	int i, j;
	i = j = 0;
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);

	///////// CALL THIS : setup(scene) {
	int image_height = (int)(WIDTH/RATIO);
	if (image_height < 1){
			image_height = 1;
	}
	
    // setup viewport
    float focal_length = 1.0;
    float viewport_height = 2.0;
    float viewport_width = viewport_height * (double)(WIDTH)/image_height;

    t_vector *viewport_u = new_vector(viewport_width, 0, 0);
    t_vector *viewport_v = new_vector(0, -viewport_height, 0);
	// pixel conversion to delta step
    t_vector *pixel_delta_u = scalar_division(viewport_u, WIDTH);
    t_vector *pixel_delta_v = scalar_division(viewport_v , image_height);
	t_vector *vec3 = new_vector( 0, 0, focal_length);

    // Calculate the location of the upper left pixel.
	//  origin - center - vector_u/2 - vector_v/2'
    t_vector *viewport_upper_left = vector_difference(vector_difference(vector_difference(&(scene->camera.point),
									vec3),scalar_division(viewport_u, 2)),scalar_division(viewport_v,2));
    t_vector *pixel_initial_loc = vector_summ(viewport_upper_left, scalar_division(vector_summ(pixel_delta_u, pixel_delta_v), 2));
	//////////// }



	// check_intersection(ray, scene){
	// 	for item into scene{
	// 		if sphere = 
	// 	}
		
	// }



	while( i < WIDTH)
	{
		j = 0;
		while( j < HEIGHT){
			// t_ray ray = create_ray(scene->camera.point, );
			// if( check_intersection(ray, scene) == true){
			t_vector *pixel_center = vector_summ(vector_summ(pixel_initial_loc, scalar_multiplication(pixel_delta_u, i)), scalar_multiplication(pixel_delta_v, j));
            t_vector *ray_direction = vector_difference(pixel_center, &(scene->camera.point));
			
            t_ray *r = create_ray(&(scene->camera.point), ray_direction);
			// check intersection function to create;
            t_vector *color = ray_color(r);
			unsigned int c  = rgbToHex(color);
			// if
				mlx_put_pixel(img, i, j, c);
			// ?
            j++;
		}
		i++;		
	}
	mlx_loop(mlx);

	return (0);
}
