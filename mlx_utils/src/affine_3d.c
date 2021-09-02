/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 01:23:34 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 01:29:39 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_point3D   translation_3D(t_point3D p, t_vector3D v)
{
    return (point3D_add(p, v));
}

t_point3D   scale_3D(t_point3D p, float cx, float cy, float cz)
{
    p.x *= cx;
    p.y *= cy;
    p.z *= cz;
    return (p);
}