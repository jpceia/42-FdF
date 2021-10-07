/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/10/07 23:26:37 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_mlx	data;

	if (argc != 2)
	{
		perror("Please provide an argument with the filename of the map");
		return (EXIT_FAILURE);
	}
	args.title = WIN_TITLE;
	args.screen_size = vec2D_create(WIN_WIDTH, WIN_HEIGHT);
	args.fname = argv[1];
	args.colors[0] = vec3D_create(0, 1, 1);
	args.colors[1] = vec3D_create(1, 0, 0);
	mlx_data_init(&data, &args);
	mlx_add_hooks(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
