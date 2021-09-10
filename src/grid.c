/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 11:12:07 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "geom.h"
#include <stdlib.h>

void	grid_init(t_grid *grid, int width, int height)
{
	int			index;
	t_point3D	*arr;

	grid->data = (t_point3D **)malloc(width * height * sizeof(**grid->data));
	if (!grid->data)
	{
		ft_putendl("Error allocating memory to grid");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < height)
	{
		arr = (t_point3D *)malloc(width * sizeof(*arr));
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

	v_max = point3D_coord(grid->data[0][0], coord);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			v = point3D_coord(grid->data[i][j], coord);
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

	v_min = point3D_coord(grid->data[0][0], coord);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			v = point3D_coord(grid->data[i][j], coord);
			if (v_min > v)
				v_min = v;
			j++;
		}
		i++;
	}
	return (v_min);
}

void	grid_print(t_grid *grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			ft_putfloat(grid->data[i][j].z);
			ft_putchar('\t');
			j++;
		}
		ft_putnbr(grid->data[i][grid->width - 1].z);
		ft_putchar('\n');
		i++;
	}
}
