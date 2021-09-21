/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 16:59:37 by jceia            ###   ########.fr       */
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

int	win_close(int keycode, t_mlx *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// TODO transform points
// TODO color gradient (test)
// TODO camera coordinates
// TODO draw grid
// TODO zoom w/ scroll
// TODO translation w/ mouse movement

int	main(int argc, char **argv)
{
	t_camera cam;
	t_grid	grid;
	t_matrix	*M;

	if (argc != 2)
	{
		ft_putendl("Please provide an argument with the filename of the map to draw");
		exit(EXIT_FAILURE);
	}
	grid_parse_file(&grid, argv[1]);
	grid_print(&grid);

	M = matrix_homogenous_translation(vec3D_create(-0.5 * (grid.width - 1), -0.5 * (grid.height - 1), 0.0));
	M = matrix_add(M, matrix_homogeneous_from3x3(matrix_rotation_euler(M_PI / 6, 0.0, 0.0), true), true);
	cam.screen_size.x = WIN_WIDTH;
	cam.screen_size.y = WIN_HEIGHT;
	cam.scaling = fminf(
		cam.screen_size.x / (fabsf(matrix_at(M, 0, 0)) * grid.width + fabsf(matrix_at(M, 0, 1)) * grid.height),
		cam.screen_size.y / (fabsf(matrix_at(M, 1, 0)) * grid.width + fabsf(matrix_at(M, 1, 1)) * grid.height)
	);
	matrix_clear(M);

	t_mlx	data;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_mlx_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
	grid_draw(&data, &cam, &grid, vec3D_create(1.0, 1.0, 1.0));
	
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, win_close, &vars);
	mlx_key_hook(data.win, win_close, &data);
	grid_clear(&grid);
	mlx_loop(data.mlx);

}
