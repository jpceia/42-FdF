/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:28:04 by jceia             #+#    #+#             */
/*   Updated: 2021/10/08 01:14:39 by jceia            ###   ########.fr       */
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
	t_matrix	*T;
	t_matrix	*Sz;	
	t_matrix	*S;
	t_matrix	*R;
	t_matrix	*M;

	T = matrix_homogenous_translation(cam->translation);
	Sz = matrix_scaling3d(vec3d_create(1, 1, cam->z_scaling));
	Sz = matrix_homogeneous_from3x3(Sz, true);
	R = matrix3x3_rotation_xyz(cam->angles);
	R = matrix_homogeneous_from3x3(R, true);
	S = matrix_scaling3d(vec3d_create(cam->scaling, cam->scaling, 0.0));
	S = matrix_homogeneous_from3x3(S, true);
	M = matrix_mul(Sz, T, true);
	M = matrix_mul(R, M, true);
	M = matrix_mul(S, M, true);
	T = matrix_homogenous_translation(
			vec3d_create(cam->offset.x, cam->offset.y, 0.0));
	M = matrix_mul(T, M, true);
	return (M);
}

t_matrix	*camera_view_transform(t_camera	*cam)
{
	t_matrix	*T;
	t_matrix	*R;

	T = matrix_homogenous_translation(cam->translation);
	R = matrix3x3_rotation_xyz(cam->angles);
	R = matrix_homogeneous_from3x3(R, true);
	return (matrix_mul(R, T, true));
}

t_camera	*camera_init(t_camera **cam, const t_grid *grid,
		t_vec2d screen_size)
{
	float		z[2];
	t_matrix	*M;

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
	M = camera_view_transform(*cam);
	if (!M)
		return (clean_exit(*cam, "Error in matrix operations", free, 0));
	z[0] = screen_size.x / (fabsf(matrix_at(M, 0, 0)) * grid->width
			+ fabsf(matrix_at(M, 0, 1)) * grid->height);
	z[1] = screen_size.y / (fabsf(matrix_at(M, 1, 0)) * grid->width
			+ fabsf(matrix_at(M, 1, 1)) * grid->height);
	(*cam)->scaling = fminf(z[0], z[1]);
	(*cam)->offset = vec2d_create(0.5 * screen_size.x, 0.5 * screen_size.y);
	(*cam)->prev_offset = (*cam)->offset;
	matrix_clear(M);
	return (*cam);
}
