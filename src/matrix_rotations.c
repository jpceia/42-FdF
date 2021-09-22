/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:57:48 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 17:39:51 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "matrix.h"
#include "fdf.h"

t_matrix	*matrix3x3_rotationX(float theta)
{
	t_matrix	*M;

	M = matrix_empty(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = 1.0;
	M->data[1] = 0.0;
	M->data[2] = 0.0;
	M->data[3] = 0.0;
	M->data[4] = cos(theta);
	M->data[5] = -sin(theta);
	M->data[6] = 0.0;
	M->data[7] = sin(theta);
	M->data[8] = cos(theta);
	return (M);
}

t_matrix	*matrix3x3_rotationY(float theta)
{
	t_matrix	*M;

	M = matrix_empty(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = cos(theta);
	M->data[1] = 0.0;
	M->data[2] = sin(theta);
	M->data[3] = 0.0;
	M->data[4] = 1.0;
	M->data[5] = 0.0;
	M->data[7] = -sin(theta);
	M->data[8] = 0.0;
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
	M->data[2] = 0.0;
	M->data[3] = sin(theta);
	M->data[4] = cos(theta);
	M->data[5] = 0.0;
	M->data[6] = 0.0;
	M->data[7] = 0.0;
	M->data[8] = 1.0;
	return (M);
}

t_matrix	*matrix3x3_euler_rotation(float yaw, float pitch, float roll)
{
	t_matrix	*M;

	M = matrix3x3_rotationZ(yaw);
	M = matrix_mul(matrix3x3_rotationY(pitch), M, true);
	M = matrix_mul(matrix3x3_rotationX(roll), M, true);
	return (M);
}
