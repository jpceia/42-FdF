/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:28:12 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 07:09:26 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	float	t;
	float	r;
	float	g;
	float	b;
}	t_color;

typedef	int	t_trgb;

t_trgb	create_trgb(t_color color);
int		get_t(t_trgb trgb);
int		get_r(t_trgb trgb);
int		get_g(t_trgb trgb);
int		get_b(t_trgb trgb);

t_color color_interp(t_color c1, t_color c2, float t);
t_color color_create(float t, float r, float g, float b);

#endif