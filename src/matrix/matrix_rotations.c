/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:57:48 by jceia             #+#    #+#             */
/*   Updated: 2021/10/04 11:28:23 by jceia            ###   ########.fr       */
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

t_anglesXYZ	angles_xyz_create(float yaw, float pitch, float roll)
{
	t_anglesXYZ	angles;

	angles.yaw = yaw;
	angles.pitch = pitch;
	angles.roll = roll;
	return (angles);
}

t_matrix	*matrix3x3_rotation_xyz(t_anglesXYZ angles)
{
	t_matrix	*M;

	M = matrix3x3_rotation_z(angles.yaw);
	M = matrix_mul(matrix3x3_rotation_y(angles.pitch), M, true);
	M = matrix_mul(matrix3x3_rotation_x(angles.roll), M, true);
	return (M);
}
