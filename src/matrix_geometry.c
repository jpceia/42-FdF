/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:16:53 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 17:41:55 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "matrix.h"

t_matrix	*matrix_scaling3D(t_vec3D s)
{
	t_matrix	*M;

	M = matrix_empty(3, 3);
	if (!M)
		return (NULL);
	M->data[0] = s.x;
	M->data[1] = 0.0;
	M->data[2] = 0.0;
	M->data[3] = 0.0;
	M->data[4] = s.y;
	M->data[5] = 0.0;
	M->data[6] = 0.0;
	M->data[7] = 0.0;
	M->data[8] = s.z;
	return (M);
}

t_vec3D	matrix_mul_vec3D(t_matrix *M, t_vec3D p)
{
	t_vec3D	q;

	if (!check_matrix_ncols(M->ncols, 3) || !check_matrix_nrows(M->nrows, 3))
		return (vec3D_origin());
	q.x = M->data[0] * p.x + M->data[1] * p.y + M->data[2] * p.z;
	q.y = M->data[3] * p.x + M->data[4] * p.y + M->data[5] * p.z;
	q.z = M->data[6] * p.x + M->data[7] * p.y + M->data[8] * p.z;
	return (q);
}

t_matrix	*matrix_homogeneous_from3x3(t_matrix *A, t_bool do_free)
{
	t_matrix	*M;

	if (!check_matrix_ncols(A->ncols, 3) || !check_matrix_nrows(A->nrows, 3))
		return (NULL);
	M = matrix_zeros(4, 4);
	if (!M)
		return (NULL);
	M->data[0] = A->data[0];
	M->data[1] = A->data[1];
	M->data[2] = A->data[2];
	M->data[4] = A->data[3];
	M->data[5] = A->data[4];
	M->data[6] = A->data[5];
	M->data[8] = A->data[6];
	M->data[9] = A->data[7];
	M->data[10] = A->data[8];
	M->data[15] = 1.0;
	if (do_free)
		matrix_clear(A);
	return (M);
}

t_matrix	*matrix_homogenous_translation(t_vec3D v)
{
	t_matrix	*M;

	M = matrix_zeros(4, 4);
	if (!M)
		return (NULL);
	M->data[3] = v.x;
	M->data[7] = v.y;
	M->data[11] = v.z;
	M->data[15] = 1.0;
	return (M);
}

t_vec3D	matrix_homogenous_mul_vec3D(t_matrix *M, t_vec3D p)
{
	float	w;
	t_vec3D	q;

	if (!check_matrix_ncols(M->ncols, 4) || !check_matrix_nrows(M->nrows, 4))
		return (vec3D_origin());
	if (M->data[12] != 1.0)
	{
		ft_putendl_error("Non homogeous matrix (M_44 != 1)");
		return (vec3D_origin());
	}
	w = M->data[12] * p.x + M->data[12] * p.y + M->data[12] * p.z;
	q.x = (M->data[0] * p.x + M->data[1] * p.y
			+ M->data[2] * p.z + M->data[3]) / w;
	q.y = (M->data[4] * p.x + M->data[5] * p.y
			+ M->data[6] * p.z + M->data[7]) / w;
	q.z = (M->data[8] * p.x + M->data[9] * p.y
			+ M->data[10] * p.z + M->data[11]) / w;
	return (q);
}
