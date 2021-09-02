/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:50:23 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 01:31:32 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOM_H
# define GEOM_H

# define SQRT_2 1.4142135623730951
# define SQRT_3 1.7320508075688772
# define SQRT_6 2.449489742783178

/*
 * 2D Structures
 */
typedef struct s_point2D
{
	float	x;
	float	y;
}	t_point2D;

typedef t_point2D	t_vector2D;

typedef struct s_line2D
{
	t_point2D	start;
	t_point2D	end;
}	t_line2D;

t_point2D	point2D_create(float x, float y);
t_vector2D	point2D_subtract(t_point2D a, t_point2D b);
t_point2D	point2D_add(t_point2D a, t_vector2D v);
t_vector2D	point2D_scalar_mul(t_vector2D v, float l);

t_point2D   translation_2D(t_point2D p, t_vector2D v);
t_point2D   scale_2D(t_point2D p, float c1, float c2);

/*
 * 3D Structures
 */
typedef struct s_point3D
{
	float	x;
	float	y;
	float	z;
}	t_point3D;

typedef t_point3D	t_vector3D;

typedef struct s_line3D
{
	t_point3D	start;
	t_point3D	end;
}	t_line3D;

t_point3D	point3D_create(float x, float y, float z);
t_vector3D	point3D_subtract(t_point3D a, t_point3D b);
t_point3D	point3D_add(t_point3D a, t_vector3D v);
t_vector3D	point3D_scalar_mul(t_vector3D v, float l);

t_point3D   translation_3D(t_point3D p, t_vector3D v);
t_point3D   scale_3D(t_point3D p, float cx, float cy, float cz);

/*
 * Projections 3D -> 2D
 */
t_point2D   proj_isometric(t_point3D p);

#endif