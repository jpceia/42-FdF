/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:27:46 by jceia             #+#    #+#             */
/*   Updated: 2021/09/01 23:31:24 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

t_point2D	point2D_create(float x, float y)
{
	t_point2D   p;

	p.x = x;
	p.y = y;
	return (p);
}

t_vector2D	point2D_subtract(t_point2D a, t_point2D b)
{
	return (point2D_create(a.x - b.x, a.y - b.y));
}

t_point2D	point2D_add(t_point2D a, t_vector2D v)
{
	return (point2D_create(a.x + v.x, a.y + v.y));
}

t_vector2D	point2D_scalar_mul(t_vector2D v, float l)
{
	return (point2D_create(l * v.x, l * v.y));
}
