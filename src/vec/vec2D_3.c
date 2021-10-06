/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2D_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 09:39:38 by jceia             #+#    #+#             */
/*   Updated: 2021/10/06 07:19:44 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "vec.h"

float	vec2D_norm_squared(t_vec2D v)
{
	return (v.x * v.x + v.y * v.y);
}

float	vec2D_norm(t_vec2D v)
{
	return (sqrtf(vec2D_norm_squared(v)));
}

float	vec2D_angle(t_vec2D u, t_vec2D v)
{
	float	norm_u;
	float	norm_v;
	float	dot_uv;

	dot_uv = vec2D_dot_product(u, v);
	if (dot_uv == 0)
		return (0);
	norm_u = vec2D_norm(u);
	norm_v = vec2D_norm(v);
	if (norm_u == 0 || norm_v == 0)
	{
		perror("Vector with zero length");
		return (-1);
	}
	return (dot_uv / norm_u / norm_v);
}

t_vec2D	vec2D_elementwise_product(t_vec2D u, t_vec2D v)
{
	u.x *= v.x;
	u.y *= v.y;
	return (u);
}

t_vec2D	vec2D_clip(t_vec2D v, float a, float b)
{
	v.x = fminf(fmaxf(v.x, a), b);
	v.y = fminf(fmaxf(v.y, a), b);
	return (v);
}
