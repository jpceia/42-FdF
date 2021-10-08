/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/10/08 01:08:46 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

t_grid	*grid_apply_transformation(t_grid *grid, t_matrix *M)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			grid->data[i][j] = matrix_homogenous_mul_vec3d(M, grid->data[i][j]);
			j++;
		}
		i++;
	}
	return (grid);
}

void	grid_draw_horizontal(t_mlx *data, const t_grid *grid)
{
	t_vec2d	p[2];
	t_vec3d	color[2];
	int		i;
	int		j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			p[0].x = grid->data[i][j].x;
			p[0].y = grid->data[i][j].y;
			p[1].x = grid->data[i][j + 1].x;
			p[1].y = grid->data[i][j + 1].y;
			color[0] = data->color_grid->data[i][j];
			color[1] = data->color_grid->data[i][j + 1];
			plot_line(data, p, color);
			j++;
		}
		i++;
	}
}

void	grid_draw_vertical(t_mlx *data, const t_grid *grid)
{
	t_vec2d	p[2];
	t_vec3d	color[2];
	int		i;
	int		j;

	i = 0;
	while (i < grid->height - 1)
	{
		j = 0;
		while (j < grid->width)
		{
			p[0].x = grid->data[i][j].x;
			p[0].y = grid->data[i][j].y;
			p[1].x = grid->data[i + 1][j].x;
			p[1].y = grid->data[i + 1][j].y;
			color[0] = data->color_grid->data[i][j];
			color[1] = data->color_grid->data[i + 1][j];
			plot_line(data, p, color);
			j++;
		}
		i++;
	}
}

void	grid_draw(t_mlx *data)
{
	t_matrix	*M;
	t_grid		*grid_cpy;

	M = camera_transform(data->cam);
	if (!M)
		clean_exit(data, "Error calculating the camera transform",
			mlx_data_clear, 1);
	grid_cpy = grid_clone(data->grid);
	if (!grid_cpy)
		clean_exit(data, "Error creating a grid clone", mlx_data_clear, 1);
	grid_apply_transformation(grid_cpy, M);
	matrix_clear(M);
	grid_draw_horizontal(data, grid_cpy);
	grid_draw_vertical(data, grid_cpy);
	grid_clear(grid_cpy);
}
