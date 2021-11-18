/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:23:27 by jceia             #+#    #+#             */
/*   Updated: 2021/11/18 11:37:48 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/**
 * @brief	Draws a point on the mlx image.
 * 
 * @param	data	the mlx data structure.
 * @param	p		the point to draw.
 * @param	color	the color of the point.
 */
void	plot_pixel(t_mlx *data, t_vec2d p, t_vec3d color)
{
	int		i;
	int		j;
	char	*dst;

	i = (int)(p.x + 0.5);
	j = (int)(p.y + 0.5);
	if (i < 0 || i >= data->width || j < 0 || j >= data->height)
		return ;
	dst = data->addr + (j * data->line_length + i * (data->bits_per_pixel / 8));
	*(unsigned int *)dst += create_trgb(color);
}

/**
 * @brief	Draws a line between two points on the mlx image.
 * 			The resulting line will be a gradient between the two colors.
 * 
 * @param	data	the mlx data structure.
 * @param	p		an array of two points (start and end).
 * @param	color	an array of two colors (start and end).
 */
void	plot_line(t_mlx *data, t_vec2d p[2], t_vec3d color[2])
{
	int		i;
	int		steps;
	float	t;
	t_vec2d	direction;
	t_vec2d	r;

	steps = ft_imax(
			ft_iabs((int)(p[1].x + 0.5) - (int)(p[0].x + 0.5)),
			ft_iabs((int)(p[1].y + 0.5) - (int)(p[0].y + 0.5)));
	direction = vec2d_subtract(p[1], p[0]);
	i = 0;
	while (i <= steps)
	{
		t = (float)i / steps;
		r = vec2d_add(p[0], vec2d_scalar_mul(direction, t));
		plot_pixel(data, r, vec3d_interpolate(color[0], color[1], t));
		i++;
	}
}
