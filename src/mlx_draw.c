/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:23:27 by jceia             #+#    #+#             */
/*   Updated: 2021/10/05 22:25:34 by jceia            ###   ########.fr       */
/*                                                                            */
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
void	plot_pixel(t_mlx *data, t_vec2D p, t_vec3D color)
{
	int		i;
	int		j;
	char	*dst;

	i = (int)(p.x + 0.5);
	j = (int)(p.y + 0.5);
	if (i < 0 || i > data->width || j < 0 || j > data->height)
		return ;
	dst = data->addr + (j * data->line_length + i * (data->bits_per_pixel / 8));
	*(unsigned int *)dst += create_trgb(color);
}

void	plot_line(t_mlx *data, t_vec2D p, t_vec2D q, t_vec3D color)
{
	int		i;
	int		steps;
	float	t;
	t_vec2D	direction;
	t_vec2D	r;

	steps = vec2D_norm(vec2D_subtract(q, p));
	direction = vec2D_subtract(q, p);
	i = 0;
	while (i <= steps)
	{
		t = (float)i / steps;
		r = vec2D_add(p, vec2D_scalar_mul(direction, t));
		plot_pixel(data, r, color);
		i++;
	}
}
