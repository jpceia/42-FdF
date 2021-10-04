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


void	camera_init(t_camera *cam, const t_fdf_args *args)
{
	float		s[2];
	t_matrix	*T;
	t_matrix	*R;
	t_matrix	*M;

	cam->translation = vec3D_create(
			-0.5 * (args->grid.width - 1), -0.5 * (args->grid.height - 1), 0.0);
	cam->angles.yaw = M_PI / 4;
	cam->angles.pitch = 0;
	cam->angles.roll = atanf(1 / sqrtf(2));
	T = matrix_homogenous_translation(cam->translation);
	R = matrix3x3_rotation_xyz(cam->angles);
	R = matrix_homogeneous_from3x3(R, true);
	M = matrix_mul(R, T, true);
	s[0] = args->width / (fabsf(matrix_at(M, 0, 0)) * args->grid.width + fabsf(matrix_at(M, 0, 1)) * args->grid.height);
	s[1] = args->height / (fabsf(matrix_at(M, 1, 0)) * args->grid.width + fabsf(matrix_at(M, 1, 1)) * args->grid.height);
	cam->scaling = fminf(s[0], s[1]);
	cam->offset = vec2D_create(args->width / 2.0, args->height / 2.0);
	matrix_clear(M);
}

void	keys_init(t_keys *keys)
{
	keys->down_arrow = 0;
	keys->left_arrow = 0;
	keys->right_arrow = 0;
	keys->up_arrow = 0;
}

void	mlx_data_init(t_mlx *data, const t_fdf_args *args)
{
	
	data->mlx = mlx_init();
	camera_init(&(data->cam), args);
	data->width = args->width;
	data->height = args->height;
	data->grid = args->grid;
	data->win = mlx_new_window(data->mlx, args->width, args->height, args->title);
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
