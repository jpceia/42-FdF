/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:23:27 by jceia             #+#    #+#             */
/*   Updated: 2021/10/07 23:28:19 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	plot_pixel(t_mlx *data, t_vec2D p, t_vec3D color)
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

void	plot_line(t_mlx *data, t_vec2D p[2], t_vec3D color[2])
{
	int		i;
	int		steps;
	float	t;
	t_vec2D	direction;
	t_vec2D	r;

	steps = ft_imax(
			ft_iabs((int)(p[1].x + 0.5) - (int)(p[0].x + 0.5)),
			ft_iabs((int)(p[1].y + 0.5) - (int)(p[0].y + 0.5)));
	direction = vec2D_subtract(p[1], p[0]);
	i = 0;
	while (i <= steps)
	{
		t = (float)i / steps;
		r = vec2D_add(p[0], vec2D_scalar_mul(direction, t));
		plot_pixel(data, r, vec3D_interpolate(color[0], color[1], t));
		i++;
	}
}
