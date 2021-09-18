/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 02:53:52 by jceia             #+#    #+#             */
/*   Updated: 2021/09/17 10:41:57 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trgb	create_trgb(t_vec3D color)
{
	return (
		  ((int)(255 * color.x)) << 16
		| ((int)(255 * color.y)) << 8
		| ((int)(255 * color.z)));
}


t_rgb color_create(float r, float g, float b)
{
    t_rgb color;
    color.x = r;
    color.y = g;
    color.z = b;
    return (color);
}