/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3D_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 09:39:38 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 17:52:21 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "vec.h"

float	vec3D_norm_squared(t_vec3D v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float	vec3D_norm(t_vec3D v)
{
	return (sqrtf(vec3D_norm_squared(v)));
}

float	vec3D_angle(t_vec3D u, t_vec3D v)
{
	float	norm_u;
	float	norm_v;
	float	dot_uv;

	dot_uv = vec3D_dot_product(u, v);
	if (dot_uv == 0)
		return (0);
	norm_u = vec3D_norm(u);
	norm_v = vec3D_norm(v);
	if (norm_u == 0 || norm_v == 0)
	{
		ft_putstr_error("Impossible to calculate angle between two vectors");
		ft_putendl_error("where one of them has zero lenght");
		return (-1);
	}
	return (dot_uv / norm_u / norm_v);
}

t_vec3D	vec3D_elementwise_product(t_vec3D u, t_vec3D v)
{
	u.x *= v.x;
	u.y *= v.y;
	u.z *= v.z;
	return (u);
}

t_vec3D	vec3D_clip(t_vec3D v, float a, float b)
{
	v.x = fminf(fmaxf(v.x, a), b);
	v.y = fminf(fmaxf(v.y, a), b);
	v.z = fminf(fmaxf(v.z, a), b);
	return (v);
}
