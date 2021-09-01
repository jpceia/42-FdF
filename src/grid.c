/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 00:17:03 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "geom_utils.h"
#include <stdlib.h>

void	grid_init(t_grid *grid, int width, int height)
{
	int		index;
	float	*arr;
	
	grid->data = (float **)malloc(width * height * sizeof(**grid->data));
	if (!grid->data)
	{
		ft_putendl("Error allocating memory to grid");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < height)
	{
		arr = (float *)malloc(width * sizeof(*arr));
		if (!arr)
		{
			ft_putendl_error("Error assigning memory to array");
			exit(EXIT_FAILURE);
		}
		grid->data[index] = arr;
		index++;
	}
	grid->width = width;
	grid->height = height;
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

float	grid_max(t_grid *grid)
{
	float	v;
	int		i;
	int		j;

	v = grid->data[0][0];
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			if (v > grid->data[i][j])
				v = grid->data[i][j];
			j++;
		}
		i++;
	}
	return (v);
}

float	grid_min(t_grid *grid)
{
	float	v;
	int		i;
	int		j;

	v = grid->data[0][0];
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			if (v < grid->data[i][j])
				v = grid->data[i][j];
			j++;
		}
		i++;
	}
	return (v);
}
