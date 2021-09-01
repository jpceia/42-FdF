/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:32:05 by jceia             #+#    #+#             */
/*   Updated: 2021/09/01 22:33:11 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

t_point3D	point3D_create(float x, float y, float z)
{
	t_point3D   p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vector3D	point3D_subtract(t_point3D a, t_point3D b)
{
	return (point3D_create(b.x - a.x, b.y - a.y, b.z - a.z));
}

t_point3D	point3D_add(t_point3D a, t_vector3D v)
{
	return (point3D_create(a.x + v.x, a.y + v.y, a.z + v.z));
}

t_vector3D	point3D_scalar_mul(t_vector3D v, float l)
{
	return (point3D_create(l * v.x, l * v.y, l * v.z));
}
