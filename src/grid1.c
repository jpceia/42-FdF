/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/09/22 08:37:16 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	grid_init(t_grid *grid, int width, int height)
{
	int		index;
	t_vec3D	*arr;

	grid->data = (t_vec3D **)malloc(width * height * sizeof(**grid->data));
	if (!grid->data)
	{
		ft_putendl("Error allocating memory to grid");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < height)
	{
		arr = (t_vec3D *)malloc(width * sizeof(*arr));
		if (!arr)
		{
			ft_putendl_error("Error assigning memory to array");
			grid->height = index;
			grid_clear(grid);
			exit(EXIT_FAILURE);
		}
		grid->data[index] = arr;
		index++;
	}
	grid->width = width;
	grid->height = height;
}

t_grid	grid_clone(const t_grid *grid)
{
	int		i;
	int		j;
	t_grid	grid_cpy;

	grid_init(&grid_cpy, grid->width, grid->height);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			grid_cpy.data[i][j] = grid->data[i][j];
			j++;
		}
		i++;
	}
	return (grid_cpy);
}

void	grid_clear(t_grid *grid)
{
	int	index;

	index = 0;
	while (index < grid->height)
	{
		free(grid->data[index]);
		index++;
	}
	free(grid->data);
}

float	grid_max(t_grid *grid, t_coord coord)
{
	float	v_max;
	float	v;
	int		i;
	int		j;

	v_max = vec3D_coord(grid->data[0][0], coord);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			v = vec3D_coord(grid->data[i][j], coord);
			if (v_max < v)
				v_max = v;
			j++;
		}
		i++;
	}
	return (v_max);
}

float	grid_min(t_grid *grid, t_coord coord)
{
	float	v_min;
	float	v;
	int		i;
	int		j;

	v_min = vec3D_coord(grid->data[0][0], coord);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			v = vec3D_coord(grid->data[i][j], coord);
			if (v_min > v)
				v_min = v;
			j++;
		}
		i++;
	}
	return (v_min);
}
