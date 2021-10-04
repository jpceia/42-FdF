/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/10/04 12:29:20 by jceia            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fdf_args	args;
	t_mlx		data;
	t_grid		grid;

	if (argc != 2)
	{
		perror("Please provide an argument with the filename of the map");
		return (EXIT_FAILURE);
	}
	grid_parse_file(&grid, argv[1]);
	args.title = WIN_TITLE;
	args.width = WIN_WIDTH;
	args.height = WIN_HEIGHT;
	args.grid = grid;
	mlx_data_init(&data, &args);
	mlx_add_hooks(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
