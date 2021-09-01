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

#include "mlx_utils.h"
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
void	plot_pixel(t_data *data, t_point2D p, t_color color)
{
	char	*dst;

	dst = data->addr + ((int)(p.y + 0.5)*data->line_length
			+ (int)(p.x + 0.5)*(data->bits_per_pixel / 8));
	*(unsigned int *)dst += color;
}

void	plot_line(t_data *data, t_line2D line, t_gradient g)
{
	int			i;
	int			steps;
	float		t;
	t_vector2D	direction;
	t_point2D	p;

	steps = ft_imax(
			ft_iabs((int)(line.start.x - line.end.x)),
			ft_iabs((int)(line.start.y - line.end.y)));
	direction = point2D_subtract(line.end, line.start);
	i = 0;
	while (i < steps)
	{
		t = (float)i / steps;
		p = point2D_add(line.start, point2D_scalar_mul(direction, t));
		plot_pixel(data, p, g.color_start + t * (g.color_end - g.color_start));
		i++;
	}
}
