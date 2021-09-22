/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:23:36 by jceia             #+#    #+#             */
/*   Updated: 2021/09/22 16:50:27 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef enum e_coord
{
	COORD_X,
	COORD_Y,
	COORD_Z
}	t_coord;

/*
 * vec2D
 */
typedef struct s_vec2D
{
	float	x;
	float	y;
}	t_vec2D;

t_vec2D	vec2D_create(float x, float y);
t_vec2D	vec2D_origin(void);
t_vec2D	vec2D_subtract(t_vec2D q, t_vec2D p);
t_vec2D	vec2D_add(t_vec2D p, t_vec2D v);
float	vec2D_coord(t_vec2D p, t_coord coord);

t_vec2D	vec2D_scalar_mul(t_vec2D v, float l);
t_vec2D	vec2D_normalize(t_vec2D v);
float	vec2D_cross_product(t_vec2D u, t_vec2D v);
t_vec2D	vec2D_elementwise_product(t_vec2D u, t_vec2D v);
t_vec2D	vec2D_interpolate(t_vec2D p, t_vec2D q, float t);

float	vec2D_dot_product(t_vec2D u, t_vec2D v);
float	vec2D_norm_squared(t_vec2D v);
float	vec2D_norm(t_vec2D v);
float	vec2D_angle(t_vec2D u, t_vec2D v);
t_vec2D	vec2D_clip(t_vec2D v, float a, float b);
/*
 * vec3D
 */

typedef struct s_vec3D
{
	float	x;
	float	y;
	float	z;
}	t_vec3D;

t_vec3D	vec3D_create(float x, float y, float z);
t_vec3D	vec3D_origin(void);
t_vec3D	vec3D_subtract(t_vec3D q, t_vec3D p);
t_vec3D	vec3D_add(t_vec3D p, t_vec3D v);
float	vec3D_coord(t_vec3D p, t_coord coord);

t_vec3D	vec3D_scalar_mul(t_vec3D v, float l);
t_vec3D	vec3D_normalize(t_vec3D v);
t_vec3D	vec3D_cross_product(t_vec3D u, t_vec3D v);
t_vec3D	vec3D_elementwise_product(t_vec3D u, t_vec3D v);
t_vec3D	vec3D_interpolate(t_vec3D p, t_vec3D q, float t);

float	vec3D_dot_product(t_vec3D u, t_vec3D v);
float	vec3D_norm_squared(t_vec3D v);
float	vec3D_norm(t_vec3D v);
float	vec3D_angle(t_vec3D u, t_vec3D v);
t_vec3D	vec3D_clip(t_vec3D v, float a, float b);

#endif