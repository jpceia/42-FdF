/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:32:05 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 08:17:04 by jceia            ###   ########.fr       */
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

t_point3D	point3D_origin(void)
{
	return (point3D_create(0.0, 0.0, 0.0));
}

t_vector3D	point3D_subtract(t_point3D p, t_point3D q)
{
	p.x -= q.x;
	p.y -= q.y;
	p.z -= q.z;
	return (p);
}

t_point3D	point3D_add(t_point3D p, t_vector3D v)
{
	p.x += v.x;
	p.y += v.y;
	p.z += v.z;
	return (p);
}

t_point3D	point3D_apply(t_matrix4x4 M, t_point3D p)
{
	t_point3D	q;
	float		w;

	w = M[3][0] * p.x + M[3][1] * p.y + M[3][2] * p.z + 1;
	q.x = (M[0][0] * p.x + M[0][1] * p.y + M[0][2] * p.z + M[0][3]) / w;
	q.y = (M[1][0] * p.x + M[1][1] * p.y + M[1][2] * p.z + M[1][3]) / w;
	q.z = (M[2][0] * p.x + M[2][1] * p.y + M[2][2] * p.z + M[2][3]) / w;
	return (q);
}