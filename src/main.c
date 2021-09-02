/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 02:52:58 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#include "geom.h"
#include "mlx_utils.h"
#include <stdio.h>
#include <mlx.h>

int	win_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);	
}

int	main(int argc, char **argv)
{
	t_grid	grid;

	if (argc != 2)
	{
		ft_putendl("Please provide an argument with the filename of the map to draw");
		exit(EXIT_FAILURE);
	}
	grid_parse_file(&grid, argv[1]);

	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, win_close, &vars);
	mlx_key_hook(vars.win, win_close, &vars);

	//grid_print(&grid);
	t_gradient g;
	t_color color_start =	0x00FFFFFF;
	t_color	color_end =		0x000000FF;

	double g_max = grid_max(&grid);
	double g_min = grid_min(&grid);
	float scale_src = ft_imax(grid.height, grid.width);
	scale_src = ft_imax(scale_src, g_max - g_min);
	float scale_dest = ft_imax(WIN_HEIGHT, WIN_WIDTH);

	for (int i = 0; i < grid.height - 1; i++)
	{
		for (int j = 0; j < grid.width - 1; j++)
		{
			t_line2D line;
			printf("%d %d\n", i, j);
			line.start	= proj_isometric(point3D_create(i / scale_src, j/ scale_src, (grid.data[i][j] - g_min) / scale_src));
			line.end	= proj_isometric(point3D_create(i / scale_src, (j+1)/ scale_src , (grid.data[i][j+1] - g_min) / scale_src));
			printf("(%f, %f) -> (%f, %f)\n", line.start.x, line.start.y, line.end.x, line.end.y);
			line.start	= scale_2D(translation_2D(line.start,	point2D_create(SQRT_2, .1)), .5 * scale_dest, -.5 * scale_dest);
			line.end	= scale_2D(translation_2D(line.end,		point2D_create(SQRT_2, .1)), .5 * scale_dest, -.5 * scale_dest);
			line.start	= translation_2D(line.start,	point2D_create(0, WIN_HEIGHT));
			line.end	= translation_2D(line.end,		point2D_create(0, WIN_HEIGHT));
			printf("(%f, %f) -> (%f, %f)\n", line.start.x, line.start.y, line.end.x, line.end.y);
			g.color_start = color_start + (color_end - color_start) * (grid.data[i][j] - g_min) / scale_src;
			g.color_end = color_start + (color_end - color_start) * (grid.data[i][j+1] - g_min) / scale_src;
			plot_line(&img, line, g);
		}
	}
	
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	grid_clear(&grid);
	mlx_loop(vars.mlx);

	
}
