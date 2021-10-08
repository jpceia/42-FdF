/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:28:04 by jceia             #+#    #+#             */
/*   Updated: 2021/10/08 01:19:54 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

float	calculate_z_scaling(float grid_size, float z_min, float z_max)
{
	if (z_min >= z_max)
		return (1.0);
	return (fminf(0.25 * grid_size / (z_max - z_min), 1));
}

t_matrix	*camera_transform(const t_camera *cam)
{
	t_matrix	*t;
	t_matrix	*s_z;	
	t_matrix	*s;
	t_matrix	*r;
	t_matrix	*m;

	t = matrix_homogenous_translation(cam->translation);
	s_z = matrix_scaling3d(vec3d_create(1, 1, cam->z_scaling));
	s_z = matrix_homogeneous_from3x3(s_z, true);
	r = matrix3x3_rotation_xyz(cam->angles);
	r = matrix_homogeneous_from3x3(r, true);
	s = matrix_scaling3d(vec3d_create(cam->scaling, cam->scaling, 0.0));
	s = matrix_homogeneous_from3x3(s, true);
	m = matrix_mul(s_z, t, true);
	m = matrix_mul(r, m, true);
	m = matrix_mul(s, m, true);
	t = matrix_homogenous_translation(
			vec3d_create(cam->offset.x, cam->offset.y, 0.0));
	m = matrix_mul(t, m, true);
	return (m);
}

t_matrix	*camera_view_transform(t_camera	*cam)
{
	t_matrix	*t;
	t_matrix	*r;

	t = matrix_homogenous_translation(cam->translation);
	r = matrix3x3_rotation_xyz(cam->angles);
	r = matrix_homogeneous_from3x3(r, true);
	return (matrix_mul(r, t, true));
}

t_camera	*camera_init(t_camera **cam, const t_grid *grid,
		t_vec2d screen_size)
{
	float		z[2];
	t_matrix	*m;

	*cam = (t_camera *)malloc(sizeof(**cam));
	if (!*cam)
		return (clean_exit(*cam, "Error alocating memory", NULL, 0));
	z[0] = grid_min(grid, COORD_Z);
	z[1] = grid_max(grid, COORD_Z);
	(*cam)->translation = vec3d_scalar_mul(vec3d_create(grid->width - 1,
				grid->height - 1, z[0] + z[1]), -0.5);
	(*cam)->z_scaling = calculate_z_scaling(
			fmaxf(grid->height, grid->width), z[0], z[1]);
	(*cam)->angles = vec3d_create(atanf(1 / sqrtf(2)), 0.0, M_PI / 4);
	m = camera_view_transform(*cam);
	if (!m)
		return (clean_exit(*cam, "Error in matrix operations", free, 0));
	z[0] = screen_size.x / (fabsf(matrix_at(m, 0, 0)) * grid->width
			+ fabsf(matrix_at(m, 0, 1)) * grid->height);
	z[1] = screen_size.y / (fabsf(matrix_at(m, 1, 0)) * grid->width
			+ fabsf(matrix_at(m, 1, 1)) * grid->height);
	(*cam)->scaling = fminf(z[0], z[1]);
	(*cam)->offset = vec2d_create(0.5 * screen_size.x, 0.5 * screen_size.y);
	(*cam)->prev_offset = (*cam)->offset;
	matrix_clear(m);
	return (*cam);
}
