/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/09/24 14:51:07 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#include <stdio.h>
#include <mlx.h>
#include <math.h>

int	key_handle(int keycode, t_mlx *vars)
{
	printf("key: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}



void	mlx_setup_data(t_mlx *data, t_camera *cam, const t_vec2D *screen_size, char *title)
{
	data->mlx = mlx_init();
	data->cam = cam;
	data->width = screen_size->x;
	data->height = screen_size->y;
	data->win = mlx_new_window(data->mlx, data->width, data->height, title);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), &(data->line_length),
									&(data->endian));
}

void	mlx_clear_data(t_mlx *data)
{
	(void)data;
}

// https://groups.google.com/g/comp.graphics.api.opengl/c/9fS5o2QtyPc
int	main(int argc, char **argv)
{
	t_vec2D	screen_size;
	t_mlx	data;
	t_camera cam;

	t_grid	grid;
	t_matrix	*T;
	t_matrix	*M;
	t_matrix	*R;

	if (argc != 2)
	{
		ft_putendl("Please provide an argument with the filename of the map to draw");
		exit(EXIT_FAILURE);
	}
	grid_parse_file(&grid, argv[1]);

	cam.translation = vec3D_create(-0.5 * (grid.width - 1), -0.5 * (grid.height - 1), 0.0);
	cam.euler_angles.yaw = atanf(1 / sqrtf(2));
	cam.euler_angles.roll = M_PI/3;
	cam.euler_angles.pitch = M_PI/ 4;
	T = matrix_homogenous_translation(cam.translation);
	R = matrix3x3_euler_rotation(cam.euler_angles);
	R = matrix_homogeneous_from3x3(R, true);
	M = matrix_mul(R, T, true);
	screen_size = vec2D_create(WIN_WIDTH, WIN_HEIGHT);
	float tmp1 = screen_size.x / (fabsf(matrix_at(M, 0, 0)) * grid.width + fabsf(matrix_at(M, 0, 1)) * grid.height);
	float tmp2 = screen_size.y / (fabsf(matrix_at(M, 1, 0)) * grid.width + fabsf(matrix_at(M, 1, 1)) * grid.height);
	matrix_clear(M);
	cam.scaling = fminf(tmp1, tmp2);
	mlx_setup_data(&data, &cam, &screen_size, WIN_TITLE);
	grid_draw(&data, &cam, &grid, vec3D_create(1.0, 1.0, 1.0));
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_handle, &data);
	mlx_loop(data.mlx);
	grid_clear(&grid);
}
