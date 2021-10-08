/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:16:53 by jceia             #+#    #+#             */
/*   Updated: 2021/10/08 01:18:55 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "matrix.h"

t_matrix	*matrix_scaling3d(t_vec3d s)
{
	t_matrix	*m;

	m = matrix_zeros(3, 3);
	if (!m)
		return (NULL);
	m->data[0] = s.x;
	m->data[4] = s.y;
	m->data[8] = s.z;
	return (m);
}

t_vec3d	matrix_mul_vec3d(t_matrix *m, t_vec3d p)
{
	t_vec3d	q;

	if (!m)
		return (vec3d_origin());
	if (!check_matrix_ncols(m->ncols, 3) || !check_matrix_nrows(m->nrows, 3))
		return (vec3d_origin());
	q.x = m->data[0] * p.x + m->data[1] * p.y + m->data[2] * p.z;
	q.y = m->data[3] * p.x + m->data[4] * p.y + m->data[5] * p.z;
	q.z = m->data[6] * p.x + m->data[7] * p.y + m->data[8] * p.z;
	return (q);
}

t_matrix	*matrix_homogeneous_from3x3(t_matrix *A, t_bool do_free)
{
	t_matrix	*m;

	if (!A)
		return (NULL);
	if (!check_matrix_ncols(A->ncols, 3) || !check_matrix_nrows(A->nrows, 3))
		return (NULL);
	m = matrix_zeros(4, 4);
	if (!m)
		return (NULL);
	m->data[0] = A->data[0];
	m->data[1] = A->data[1];
	m->data[2] = A->data[2];
	m->data[4] = A->data[3];
	m->data[5] = A->data[4];
	m->data[6] = A->data[5];
	m->data[8] = A->data[6];
	m->data[9] = A->data[7];
	m->data[10] = A->data[8];
	m->data[15] = 1.0;
	if (do_free)
		matrix_clear(A);
	return (m);
}

t_matrix	*matrix_homogenous_translation(t_vec3d v)
{
	t_matrix	*m;

	m = matrix_zeros(4, 4);
	if (!m)
		return (NULL);
	m->data[0] = 1.0;
	m->data[3] = v.x;
	m->data[5] = 1.0;
	m->data[7] = v.y;
	m->data[10] = 1.0;
	m->data[11] = v.z;
	m->data[15] = 1.0;
	return (m);
}

t_vec3d	matrix_homogenous_mul_vec3d(t_matrix *m, t_vec3d p)
{
	float	w;
	t_vec3d	q;

	if (!m)
		return (vec3d_origin());
	if (!check_matrix_ncols(m->ncols, 4) || !check_matrix_nrows(m->nrows, 4))
		return (vec3d_origin());
	if (m->data[15] != 1.0)
	{
		perror("Non homogeous matrix (M_44 != 1)");
		return (vec3d_origin());
	}
	w = m->data[12] * p.x + m->data[13] * p.y
		+ m->data[14] * p.z + m->data[15];
	q.x = (m->data[0] * p.x + m->data[1] * p.y
			+ m->data[2] * p.z + m->data[3]) / w;
	q.y = (m->data[4] * p.x + m->data[5] * p.y
			+ m->data[6] * p.z + m->data[7]) / w;
	q.z = (m->data[8] * p.x + m->data[9] * p.y
			+ m->data[10] * p.z + m->data[11]) / w;
	return (q);
}
