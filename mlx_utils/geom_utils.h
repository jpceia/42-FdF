/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:50:23 by jceia             #+#    #+#             */
/*   Updated: 2021/09/01 22:50:39 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 * 2D Structures
 */
typedef struct s_point2D
{
	float	x;
	float	y;
}	t_point2D;

typedef	t_point2D t_vector2D;

typedef struct s_line2D
{
	t_point2D	start;
	t_point2D	end;
}	t_line2D;

t_point2D	point2D_create(float x, float y);
t_vector2D	point2D_subtract(t_point2D a, t_point2D b);
t_point2D	point2D_add(t_point2D a, t_vector2D v);
t_vector2D	point2D_scalar_mul(t_vector2D v, float l);

/*
 * 3D Structures
 */
typedef struct s_point3D
{
	float	x;
	float	y;
	float	z;
}	t_point3D;

typedef	t_point3D t_vector3D;

typedef struct s_line3D
{
	t_point3D	start;
	t_point3D	end;
}	t_line3D;

t_point3D	point3D_create(float x, float y, float z);
t_vector3D	point3D_subtract(t_point3D a, t_point3D b);
t_point3D	point3D_add(t_point3D a, t_vector3D v);
t_vector3D	point3D_scalar_mul(t_vector3D v, float l);