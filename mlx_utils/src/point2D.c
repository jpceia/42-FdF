/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:27:46 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 11:06:11 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "libft.h"

t_point2D	point2D_create(float x, float y)
{
	t_point2D	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_vector2D	point2D_subtract(t_point2D p, t_point2D q)
{
	p.x -= q.x;
	p.y -= q.y;
	return (p);
}

t_point2D	point2D_add(t_point2D p, t_vector2D v)
{
	p.x += v.x;
	p.y += v.y;
	return (p);
}

float	point2D_coord(t_point2D p, t_coord coord)
{
	switch (coord)
	{
	case COORD_X:
		return (p.x);
	case COORD_Y:
		return (p.y);
	default:
		break ;
	}
	ft_putendl_error("Invalid coordinate");
	return (0.0);
}