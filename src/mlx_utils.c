/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mlx_utils.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jceia <jceia@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/09/01 20:28:58 by jceia			 #+#	#+#			 */
/*   Updated: 2021/09/02 00:22:11 by jceia			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

/*
 * TODO
 * add_shape
 * is a function that accepts a double (distance) and a int (color) as
 * arguments, 0 will add no shading to the color, whilst 1 will make the
 * color completely dark. 0.5 will dim it halfway, and .25 a quarter way.
 * You get the point.
 */
void	plot_pixel(t_mlx *data, float x, float y, t_rgb color)
{
	int		i;
	int		j;
	char	*dst;

	i = (int)(x + 0.5);
	j = (int)(y + 0.5);
	if (i < 0 || i > data->width || j < 0 || j > data->height)
		return ;
	dst = data->addr + (j * data->line_length + i * (data->bits_per_pixel / 8));
	*(unsigned int *)dst += create_trgb(color);
}

void	plot_line(t_mlx *data, t_vec2D p, t_vec2D q, t_rgb color)
{
	int		i;
	int		steps;
	t_vec2D	direction;
	t_vec2D	r;

	steps = vec2D_norm(vec2D_subtract(q, p));
	direction = vec2D_subtract(q, p);
	i = 0;
	while (i < steps)
	{
		r = vec2D_add(p, vec2D_scalar_mul(direction, (float)i / steps));
		plot_pixel(data, r.x, r.y, color);
		i++;
	}
}


void	grid_camera_transform(t_grid *grid, const t_camera *cam)
{
	t_matrix	*M;

	M = matrix_homogenous_translation(vec3D_create(-0.5 * (grid->width - 1), -0.5 * (grid->height - 1), 0.0));
	M = matrix_mul(M, matrix_scaling3D(vec3D_create(cam->scaling, cam->scaling, 0.0)), true);
	M = matrix_mul(M, matrix3x3_euler_rotation(M_PI / 8, M_PI / 4, 0.0), true);
	grid_apply_transformation(grid, M);
	matrix_clear(M);
}

void grid_draw_horizontal(t_mlx *data, const t_grid *grid, t_rgb color)
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
			q.x = grid->data[i][j+1].x;
			q.y = grid->data[i][j+1].y;
			plot_line(data, p, q, color);
			j++;
		}
	}
}

void grid_draw_vertical(t_mlx *data, const t_grid *grid, t_rgb color)
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
			q.x = grid->data[i+1][j].x;
			q.y = grid->data[i+1][j].y;
			plot_line(data, p, q, color);
			j++;
		}
	}
}

void	grid_draw(t_mlx *data, const t_camera *cam, const t_grid *grid, t_rgb color)
{
	t_grid	grid_cpy;

	grid_cpy = grid_clone(grid);
	grid_camera_transform(&grid_cpy, cam);
	grid_draw_horizontal(data, &grid_cpy, color);
	grid_draw_vertical(data, &grid_cpy, color);
}