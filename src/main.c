/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/09/29 01:34:16 by jceia            ###   ########.fr       */
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

int	key_handle(int keycode, t_mlx *data)
{
	printf("key: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_data_clear(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}


// https://groups.google.com/g/comp.graphics.api.opengl/c/9fS5o2QtyPc
int	main(int argc, char **argv)
{
	t_vec2D		grid_size;
	t_vec2D		screen_size;
	t_mlx		data;
	t_camera	cam;
	t_grid		grid;

	if (argc != 2)
	{
		perror("Please provide an argument with the filename of the map");
		return (EXIT_FAILURE);
	}
	grid_parse_file(&grid, argv[1]);
	screen_size = vec2D_create(WIN_WIDTH, WIN_HEIGHT);
	grid_size = vec2D_create(grid.width, grid.height);
	camera_init(&cam, grid_size, screen_size);
	mlx_data_init(&data, &cam, &screen_size, WIN_TITLE);
	grid_draw(&data, &cam, &grid, vec3D_create(1.0, 1.0, 1.0));
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_handle, &data);
	mlx_loop(data.mlx);
	grid_clear(&grid);
	return (EXIT_SUCCESS);
}
