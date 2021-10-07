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

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "libft.h"


float	calculate_z_scaling(float grid_size, float z_min, float z_max)
{
	if (z_min >= z_max)
		return (1.0);
	return (fminf(0.25 * grid_size / (z_max - z_min), 1));
}

void	clean_exit(t_mlx *data, char *msg)
{
	perror(msg);
	mlx_data_clear(data);
	exit(EXIT_FAILURE);
}

int	camera_init(t_camera *cam, const t_fdf_args *args)
{
	float		z[2];
	t_matrix	*T;
	t_matrix	*M;

	z[0] = grid_min(&(args->grid), COORD_Z);
	z[1] = grid_max(&(args->grid), COORD_Z);
	cam->translation = vec3D_scalar_mul(vec3D_create(args->grid.width - 1,
				args->grid.height - 1, z[0] + z[1]), -0.5);
	cam->z_scaling = calculate_z_scaling(
			fmaxf(args->grid.height, args->grid.width), z[0], z[1]);
	cam->angles = vec3D_create(atanf(1 / sqrtf(2)), 0.0, M_PI / 4);
	T = matrix_homogenous_translation(cam->translation);
	M = matrix_homogeneous_from3x3(matrix3x3_rotation_xyz(cam->angles), true);
	M = matrix_mul(M, T, true);
	if (!M)
		return (-1);
	z[0] = args->width / (fabsf(matrix_at(M, 0, 0)) * args->grid.width
			+ fabsf(matrix_at(M, 0, 1)) * args->grid.height);
	z[1] = args->height / (fabsf(matrix_at(M, 1, 0)) * args->grid.width
			+ fabsf(matrix_at(M, 1, 1)) * args->grid.height);
	cam->scaling = fminf(z[0], z[1]);
	cam->offset = vec2D_create(args->width / 2.0, args->height / 2.0);
	cam->prev_offset = cam->offset;
	matrix_clear(M);
	return (0);
}

int	color_grid_init(t_grid *color_grid, const t_grid *grid, const t_vec3D colors[2])
{
	int		i;
	int		j;
	float	d;
	float	z[2];
	
	i = 0;
	color_grid->width = grid->width;
	color_grid->height = grid->height;
	z[0] = grid_min(grid, COORD_Z);
	z[1] = grid_max(grid, COORD_Z);
	d = fmaxf(0.25 * fmaxf(grid->width, grid->height), z[1] - z[0]);
	if (!grid_init(color_grid, grid->width, grid->height))
		return (-1);
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			color_grid->data[i][j] = vec3D_interpolate(
				colors[0], colors[1], (grid->data[i][j].z - z[0]) / d);
			j++;
		}
		i++;
	}
	return (0);
}

void	mlx_data_init(t_mlx *data, const t_fdf_args *args)
{
	if (camera_init(&(data->cam), args) < 0)
		clean_exit(data, "Failed setting up the camera");
	data->mlx = mlx_init();
	data->width = args->width;
	data->height = args->height;
	data->grid = args->grid;
	if (color_grid_init(&(data->color_grid), &(args->grid), args->colors) < 0)
		clean_exit(data, "Failed setting up color-grid");
	data->win = mlx_new_window(
			data->mlx, args->width, args->height, args->title);
	if (!data->win)
		clean_exit(data, "Failed to create a new window");
	ft_bzero(&(data->pressed), sizeof(data->pressed));
	ft_bzero(&(data->mouse), sizeof(data->mouse));
}

void	mlx_data_clear(t_mlx *data)
{
	grid_clear(&(data->grid));
	grid_clear(&(data->color_grid));
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
