/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:17:09 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 01:31:47 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_point2D   translation_2D(t_point2D p, t_vector2D v)
{
    return (point2D_add(p, v));
}

t_point2D   scale_2D(t_point2D p, float c1, float c2)
{
    p.x *= c1;
    p.y *= c2;
    return (p);
}