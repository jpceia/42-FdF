/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/09/01 23:58:36 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
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
	// grid_print(&grid);
	grid_clear(&grid);

	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 220, 220, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 220, 220);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	t_gradient g;
	g.color_start = 0x00FF0000;
	g.color_end =	0x00FFFFFF;
	t_line2D line;
	line.start = point2D_create(5, 5);
	line.end = point2D_create(190, 190);
	plot_line(&img, line, g);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, win_close, &vars);
	mlx_key_hook(vars.win, win_close, &vars);
	mlx_loop(vars.mlx);
}
