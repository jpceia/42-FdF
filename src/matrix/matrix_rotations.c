/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:57:48 by jceia             #+#    #+#             */
/*   Updated: 2021/10/05 22:08:55 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "matrix.h"
#include "fdf.h"

t_matrix	*matrix3x3_rotation_x(float theta)
{
	t_matrix	*M;

	M = matrix_zeros(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = 1.0;
	M->data[4] = cos(theta);
	M->data[5] = -sin(theta);
	M->data[7] = sin(theta);
	M->data[8] = cos(theta);
	return (M);
}

t_matrix	*matrix3x3_rotation_y(float theta)
{
	t_matrix	*M;

	M = matrix_zeros(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = cos(theta);
	M->data[2] = sin(theta);
	M->data[4] = 1.0;
	M->data[6] = -sin(theta);
	M->data[8] = cos(theta);
	return (M);
}

t_matrix	*matrix3x3_rotation_z(float theta)
{
	t_matrix	*M;

	M = matrix_zeros(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = cos(theta);
	M->data[1] = -sin(theta);
	M->data[3] = sin(theta);
	M->data[4] = cos(theta);
	M->data[8] = 1.0;
	return (M);
}

t_matrix	*matrix3x3_rotation_xyz(t_vec3D angles)
{
	t_matrix	*M;

	M = matrix3x3_rotation_z(angles.z);
	M = matrix_mul(matrix3x3_rotation_y(angles.y), M, true);
	M = matrix_mul(matrix3x3_rotation_x(angles.x), M, true);
	return (M);
}
