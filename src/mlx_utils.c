/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mlx_utils.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jceia <jceia@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/09/01 20:28:58 by jceia			 #+#	#+#			 */
/*   Updated: 2021/09/02 00:22:11 by jceia			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

float	calculate_z_scaling(float grid_size, float z_min, float z_max)
{
	if (z_min >= z_max)
		return (1.0);
	return (fminf(0.25 * grid_size / (z_max - z_min), 1));
}

void	camera_init(t_camera *cam, const t_fdf_args *args)
{
	float		s[2];
	float		z[2];
	t_matrix	*T;
	t_matrix	*R;
	t_matrix	*M;

	z[0] = grid_min(&(args->grid), COORD_Z);
	z[1] = grid_max(&(args->grid), COORD_Z);
	cam->translation = vec3D_scalar_mul(vec3D_create(args->grid.width - 1,
				args->grid.height - 1, z[0] + z[1]), -0.5);
	cam->z_scaling = calculate_z_scaling(
			fmaxf(args->grid.height, args->grid.width), z[0], z[1]);
	cam->angles = vec3D_create(atanf(1 / sqrtf(2)), 0.0, M_PI / 4);
	T = matrix_homogenous_translation(cam->translation);
	R = matrix3x3_rotation_xyz(cam->angles);
	R = matrix_homogeneous_from3x3(R, true);
	M = matrix_mul(R, T, true);
	s[0] = args->width / (fabsf(matrix_at(M, 0, 0)) * args->grid.width
			+ fabsf(matrix_at(M, 0, 1)) * args->grid.height);
	s[1] = args->height / (fabsf(matrix_at(M, 1, 0)) * args->grid.width
			+ fabsf(matrix_at(M, 1, 1)) * args->grid.height);
	cam->scaling = fminf(s[0], s[1]);
	cam->offset = vec2D_create(args->width / 2.0, args->height / 2.0);
	matrix_clear(M);
}

void	keys_init(t_keys *p)
{
	p->down_arrow = 0;
	p->left_arrow = 0;
	p->right_arrow = 0;
	p->up_arrow = 0;
	p->a = 0;
	p->d = 0;
	p->w = 0;
	p->s = 0;
}

void	mlx_data_init(t_mlx *data, const t_fdf_args *args)
{
	data->mlx = mlx_init();
	camera_init(&(data->cam), args);
	data->width = args->width;
	data->height = args->height;
	data->grid = args->grid;
	data->win = mlx_new_window(
			data->mlx, args->width, args->height, args->title);
	keys_init(&(data->pressed));
	data->img = NULL;
}

void	mlx_data_clear(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	grid_clear(&(data->grid));
}
