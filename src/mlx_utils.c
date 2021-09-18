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
void	plot_pixel(t_data *data, float x, float y, t_rgb color)
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

void	plot_line(t_data *data, t_vec2D p, t_vec2D q, t_rgb color)
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

t_camera	camera_build(t_vec3D orig, t_vec3D direction)
{
	t_vec3D	up_vec;
	t_camera	cam;

	cam.orig = orig;
	cam.direction = vec3D_normalize(direction);

	if (cam.direction.y == 1.0)
		up_vec = vec3D_create(0.0, 0.0, 1.0);
	else
		up_vec = vec3D_create(0.0, -1.0, 0.0);
	cam.v_x = vec3D_cross_product(cam.direction, up_vec);
	cam.v_y = vec3D_cross_product(cam.direction, cam.v_x);
	// offset_x
	// offset_y
	// width
	// height

	return (cam);
}