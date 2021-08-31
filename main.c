/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:32:53 by jceia             #+#    #+#             */
/*   Updated: 2021/08/31 22:04:42 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	t_grid	grid;

	if (argc != 2)
	{
		ft_putendl("Please provide an argument with the filename of the map to draw");
		exit(EXIT_FAILURE);
	}
	grid_parse_file(&grid, argv[1]);
	grid_print(&grid);
	//grid_clear(&grid);
}
