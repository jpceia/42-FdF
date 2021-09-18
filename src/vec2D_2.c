/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 06:48:02 by jceia             #+#    #+#             */
/*   Updated: 2021/09/17 10:19:33 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "fdf.h"

t_vec2D	vec2D_scalar_mul(t_vec2D v, float l)
{
	v.x *= l;
	v.y *= l;
	return (v);
}

t_vec2D	vec2D_normalize(t_vec2D v)
{
	return (vec2D_scalar_mul(v, 1 / vec2D_norm(v)));
}

float	vec2D_dot_product(t_vec2D u, t_vec2D v)
{
	return (u.x * v.x + u.y + v.y);
}

float	vec2D_cross_product(t_vec2D u, t_vec2D v)
{
	return (u.x * u.y - u.y * v.x);
}

t_vec2D	vec2D_interpolate(t_vec2D p, t_vec2D q, float t)
{
	t_vec2D	r;

	r.x = t * q.x + (1 - t) * p.x;
	r.y = t * q.y + (1 - t) * p.y;
	return (r);
}
