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


void	camera_init(t_camera *cam, t_vec2D grid_size, t_vec2D screen_size)
{
	float		s[2];
	t_matrix	*T;
	t_matrix	*R;
	t_matrix	*M;

	cam->translation = vec3D_create(
			-0.5 * (grid_size.x - 1), -0.5 * (grid_size.y - 1), 0.0);
	cam->angles.yaw = M_PI / 4;
	cam->angles.pitch = 0;
	cam->angles.roll = atanf(1 / sqrtf(2));
	T = matrix_homogenous_translation(cam->translation);
	R = matrix3x3_rotation_xyz(cam->angles);
	R = matrix_homogeneous_from3x3(R, true);
	M = matrix_mul(R, T, true);
	s[0] = screen_size.x / (fabsf(matrix_at(M, 0, 0)) * grid_size.x + fabsf(matrix_at(M, 0, 1)) * grid_size.y);
	s[1] = screen_size.y / (fabsf(matrix_at(M, 1, 0)) * grid_size.x + fabsf(matrix_at(M, 1, 1)) * grid_size.y);
	cam->scaling = fminf(s[0], s[1]);
	cam->offset = vec2D_create(screen_size.x / 2.0, screen_size.y / 2.0);
	matrix_clear(M);
}

void	mlx_data_init(t_mlx *data, t_camera *cam,
		const t_vec2D *screen_size, char *title)
{
	data->mlx = mlx_init();
	data->cam = cam;
	data->width = screen_size->x;
	data->height = screen_size->y;
	data->win = mlx_new_window(data->mlx, data->width, data->height, title);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
}

void	mlx_data_clear(t_mlx *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
