/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:32:05 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 01:21:52 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

t_point3D	point3D_create(float x, float y, float z)
{
	t_point3D	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vector3D	point3D_subtract(t_point3D a, t_point3D b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_point3D	point3D_add(t_point3D a, t_vector3D v)
{
	a.x += v.x;
	a.y += v.y;
	a.z += v.z;
	return (a);
}

t_vector3D	point3D_scalar_mul(t_vector3D v, float l)
{
	v.x *= l;
	v.y *= l;
	v.z *= l;
	return (v);
}