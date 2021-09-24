/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:18:41 by jceia             #+#    #+#             */
/*   Updated: 2021/09/22 17:40:27 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	matrix_pair_clear(t_matrix *A, t_matrix *B)
{
	matrix_clear(A);
	matrix_clear(B);
}

t_matrix	*matrix_mul(t_matrix *A, t_matrix *B, t_bool do_free)
{
	int			idx[3];
	t_matrix	*M;

	if (!A || !B || !check_matrix_ncols(A->ncols, B->nrows))
		return (NULL);
	M = matrix_zeros(A->nrows, B->ncols);
	idx[0] = -1;
	while (++idx[0] < A->nrows)
	{
		idx[1] = -1;
		while (++idx[1] < B->ncols)
		{
			idx[2] = -1;
			while (++idx[2] < A->ncols)
				M->data[idx[0] * M->ncols + idx[1]] += \
					matrix_at(A, idx[0], idx[2]) * matrix_at(B, idx[2], idx[1]);
		}
	}
	if (do_free)
		matrix_pair_clear(A, B);
	return (M);
}

t_matrix	*matrix_add(t_matrix *A, t_matrix *B, t_bool do_free)
{
	int			i;
	int			j;
	t_matrix	*M;

	if (!A || !B)
		return (NULL);
	if (!check_matrix_ncols(A->nrows, B->nrows))
		return (NULL);
	if (!check_matrix_nrows(A->ncols, B->ncols))
		return (NULL);
	M = matrix_empty(A->nrows, A->ncols);
	i = -1;
	while (++i < A->nrows)
	{
		j = -1;
		while (++j < B->ncols)
			M->data[i * A->ncols + j] = matrix_at(A, i, j) * matrix_at(B, i, j);
	}
	if (do_free)
		matrix_pair_clear(A, B);
	return (M);
}
