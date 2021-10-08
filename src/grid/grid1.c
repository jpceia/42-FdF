/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/10/07 22:04:53 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

t_grid	*grid_init(t_grid **grid, int width, int height)
{
	int		index;
	t_vec3d	*arr;

	*grid = (t_grid *)malloc(sizeof(**grid));
	if (!*grid)
		return (clean_exit(NULL, "Error allocating memory", NULL, 0));
	(*grid)->data = malloc(height * sizeof(arr));
	if (!(*grid)->data)
		return (clean_exit(*grid, "Error allocating memory to grid", free, 0));
	index = 0;
	while (index < height)
	{
		arr = (t_vec3d *)malloc(width * sizeof(*arr));
		if (!arr)
			return (clean_exit(*grid, "Error assigning memory to array",
					grid_clear, 0));
		(*grid)->data[index] = arr;
		index++;
	}
	(*grid)->width = width;
	(*grid)->height = height;
	return (*grid);
}

t_grid	*grid_clone(const t_grid *grid)
{
	int		i;
	int		j;
	t_grid	*grid_cpy;

	if (!grid_init(&grid_cpy, grid->width, grid->height))
		return (NULL);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			grid_cpy->data[i][j] = grid->data[i][j];
			j++;
		}
		i++;
	}
	return (grid_cpy);
}

void	grid_clear(void	*ptr)
{
	t_grid	*grid;
	int		index;

	if (!ptr)
		return ;
	grid = (t_grid *)ptr;
	if (grid->data)
	{
		index = 0;
		while (index < grid->height)
		{
			if (grid->data[index])
				free(grid->data[index]);
			index++;
		}
		free(grid->data);
	}
	free(grid);
}

float	grid_max(const t_grid *grid, t_coord coord)
{
	float	v_max;
	float	v;
	int		i;
	int		j;

	v_max = vec3d_coord(grid->data[0][0], coord);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			v = vec3d_coord(grid->data[i][j], coord);
			if (v_max < v)
				v_max = v;
			j++;
		}
		i++;
	}
	return (v_max);
}

float	grid_min(const t_grid *grid, t_coord coord)
{
	float	v_min;
	float	v;
	int		i;
	int		j;

	v_min = vec3d_coord(grid->data[0][0], coord);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			v = vec3d_coord(grid->data[i][j], coord);
			if (v_min > v)
				v_min = v;
			j++;
		}
		i++;
	}
	return (v_min);
}
