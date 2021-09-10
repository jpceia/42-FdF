/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:32:05 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 11:19:25 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "libft.h"

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

float	point3D_coord(t_point3D p, t_coord coord)
{
	switch (coord)
	{
	case COORD_X:
		return (p.x);
	case COORD_Y:
		return (p.y);
	case COORD_Z:
		return (p.z);
	}
	ft_putendl_error("Invalid coordinate");
	return (0.0);
}