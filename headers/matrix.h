/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:23:30 by jceia             #+#    #+#             */
/*   Updated: 2021/09/24 15:51:12 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "vec.h"

# ifndef NAN
#  define NAN 0xffffffff
# endif

typedef struct s_matrix
{
	int		ncols;
	int		nrows;
	float	*data;
}	t_matrix;

typedef struct s_euler_angles
{
	float	yaw;
	float	pitch;
	float	roll;
}	t_euler_angles;

t_euler_angles	euler_angles_create(float yaw, float pitch, float roll);

t_bool			check_matrix_nrows(int nrows, int _nrows);
t_bool			check_matrix_ncols(int ncols, int _ncols);

t_matrix		*matrix_empty(int ncols, int nrows);
void			matrix_clear(t_matrix *M);
t_matrix		*matrix_zeros(int ncols, int nrows);
float			matrix_at(t_matrix *A, int i, int j);
void			matrix_print(t_matrix *M);

t_matrix		*matrix_mul(t_matrix *A, t_matrix *B, t_bool do_free);
t_matrix		*matrix_add(t_matrix *A, t_matrix *B, t_bool do_free);
t_matrix		*matrix_transpose(t_matrix	*M, t_bool do_free);

t_matrix		*matrix3x3_rotationX(float theta);
t_matrix		*matrix3x3_rotationY(float theta);
t_matrix		*matrix3x3_rotationZ(float theta);
t_matrix		*matrix3x3_euler_rotation(t_euler_angles e);

t_matrix		*matrix_scaling3D(t_vec3D s);
t_vec3D			matrix_mul_vec3D(t_matrix *M, t_vec3D p);
t_matrix		*matrix_homogeneous_from3x3(t_matrix *A, t_bool do_free);
t_matrix		*matrix_homogenous_translation(t_vec3D v);
t_vec3D			matrix_homogenous_mul_vec3D(t_matrix *M, t_vec3D p);

#endif
