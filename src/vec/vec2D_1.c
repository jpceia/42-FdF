/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:32:05 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 17:50:14 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "libft.h"

t_vec2D	vec2D_create(float x, float y)
{
	t_vec2D	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_vec2D	vec2D_origin(void)
{
	return (vec2D_create(0.0, 0.0));
}

t_vec2D	vec2D_subtract(t_vec2D q, t_vec2D p)
{
	q.x -= p.x;
	q.y -= p.y;
	return (q);
}

t_vec2D	vec2D_add(t_vec2D p, t_vec2D v)
{
	p.x += v.x;
	p.y += v.y;
	return (p);
}

float	vec2D_coord(t_vec2D p, t_coord coord)
{
	if (coord == COORD_X)
		return (p.x);
	if (coord == COORD_Y)
		return (p.y);
	ft_putendl_error("Invalid coordinate");
	return (0.0);
}
