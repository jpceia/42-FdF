/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/10/05 22:12:11 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	grid_apply_transformation(t_grid *grid, t_matrix *M)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			grid->data[i][j] = matrix_homogenous_mul_vec3D(M, grid->data[i][j]);
			j++;
		}
		i++;
	}
}

void	grid_camera_transform(t_grid *grid, const t_camera *cam)
{
	t_matrix	*T;
	t_matrix	*Sz;	
	t_matrix	*S;
	t_matrix	*R;
	t_matrix	*M;

	T = matrix_homogenous_translation(cam->translation);
	Sz = matrix_scaling3D(vec3D_create(1, 1, cam->z_scaling));
	Sz = matrix_homogeneous_from3x3(Sz, true);
	R = matrix3x3_rotation_xyz(cam->angles);
	R = matrix_homogeneous_from3x3(R, true);
	S = matrix_scaling3D(vec3D_create(cam->scaling, cam->scaling, 0.0));
	S = matrix_homogeneous_from3x3(S, true);
	M = matrix_mul(Sz, T, true);
	M = matrix_mul(R, M, true);
	M = matrix_mul(S, M, true);
	T = matrix_homogenous_translation(
			vec3D_create(cam->offset.x, cam->offset.y, 0.0));
	M = matrix_mul(T, M, true);
	grid_apply_transformation(grid, M);
	matrix_clear(M);
}

void	grid_draw_horizontal(t_mlx *data, const t_grid *grid, t_vec3D color)
{
	t_vec2D	p;
	t_vec2D	q;
	int		i;
	int		j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			p.x = grid->data[i][j].x;
			p.y = grid->data[i][j].y;
			q.x = grid->data[i][j + 1].x;
			q.y = grid->data[i][j + 1].y;
			plot_line(data, p, q, color);
			j++;
		}
		i++;
	}
}

void	grid_draw_vertical(t_mlx *data, const t_grid *grid, t_vec3D color)
{
	t_vec2D	p;
	t_vec2D	q;
	int		i;
	int		j;

	i = 0;
	while (i < grid->height - 1)
	{
		j = 0;
		while (j < grid->width)
		{
			p.x = grid->data[i][j].x;
			p.y = grid->data[i][j].y;
			q.x = grid->data[i + 1][j].x;
			q.y = grid->data[i + 1][j].y;
			plot_line(data, p, q, color);
			j++;
		}
		i++;
	}
}

void	grid_draw(t_mlx *data, const t_camera *cam,
		const t_grid *grid, t_vec3D color)
{
	t_grid	grid_cpy;

	grid_cpy = grid_clone(grid);
	grid_camera_transform(&grid_cpy, cam);
	grid_draw_horizontal(data, &grid_cpy, color);
	grid_draw_vertical(data, &grid_cpy, color);
	grid_clear(&grid_cpy);
}
