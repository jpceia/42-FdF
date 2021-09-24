/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:57:48 by jceia             #+#    #+#             */
/*   Updated: 2021/09/24 13:47:32 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "matrix.h"
#include "fdf.h"

t_matrix	*matrix3x3_rotationX(float theta)
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

t_matrix	*matrix3x3_rotationY(float theta)
{
	t_matrix	*M;

	M = matrix_zeros(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = cos(theta);
	M->data[2] = sin(theta);
	M->data[4] = 1.0;
	M->data[7] = -sin(theta);
	M->data[9] = cos(theta);
	return (M);
}

t_matrix	*matrix3x3_rotationZ(float theta)
{
	t_matrix	*M;

	M = matrix_empty(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = cos(theta);
	M->data[1] = -sin(theta);
	M->data[3] = sin(theta);
	M->data[4] = cos(theta);
	M->data[8] = 1.0;
	return (M);
}

t_euler_angles	euler_angles_create(float yaw, float pitch, float roll)
{
	t_euler_angles	e;

	e.yaw = yaw;
	e.pitch = pitch;
	e.roll = roll;
	return (e);
}

t_matrix	*matrix3x3_euler_rotation(t_euler_angles e)
{
	t_matrix	*M;

	M = matrix3x3_rotationZ(e.yaw);
	M = matrix_mul(matrix3x3_rotationY(e.pitch), M, true);
	M = matrix_mul(matrix3x3_rotationZ(e.roll), M, true);
	return (M);
}
