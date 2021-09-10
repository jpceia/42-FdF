/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 02:53:52 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 07:10:02 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_trgb	create_trgb(t_color color)
{
	return (((int)(255 * color.t)) << 24
		| ((int)(255 * color.r)) << 16
		| ((int)(255 * color.g)) << 8
		| ((int)(255 * color.b)));
}

int	get_t(t_trgb trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(t_trgb trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(t_trgb trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(t_trgb trgb)
{
	return (trgb & 0xFF);
}
