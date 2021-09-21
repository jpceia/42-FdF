/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:18:41 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 16:18:45 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_mul(t_matrix *A, t_matrix *B, t_bool do_free)
{
	int			i;
	int			j;
	int			k;
	t_matrix	*M;

	if (A->ncols != B->nrows)
	{
		ft_putendl_error("#(cols A) != #(rows B)");
		return (NULL);
	}
	M = matrix_zeros(A->nrows, B->ncols);
	i = 0;
	while (i < A->nrows)
	{
		j = 0;
		while (j < B->ncols)
		{
			k = 0;
			while (k < A->ncols)
			{
				M->data[i * A->ncols + j] += A->data[i * A->ncols + k] * B->data[k * B->ncols + j];
				k++;
			}
			j++;
		}
		i++;
	}
	if (do_free)
	{
		matrix_clear(A);
		matrix_clear(B);
	}
	return (M);
}

t_matrix	*matrix_add(t_matrix *A, t_matrix *B, t_bool do_free)
{
	int			i;
	int			j;
	t_matrix	*M;

	if (A->nrows != B->nrows)
	{
		ft_putendl_error("Matrix nrows mismatch");
		return (NULL);
	}
	if (A->ncols != B->ncols)
	{
		ft_putendl_error("Matrix ncols mismatch");
		return (NULL);
	}
	M = matrix_empty(A->nrows, A->ncols);
	i = 0;
	while (i < A->nrows)
	{
		j = 0;
		while (j < B->ncols)
		{
			M->data[i * A->ncols + j] = A->data[i * A->ncols + j] * B->data[i * B->ncols + j];
			j++;
		}
		i++;
	}
	if (do_free)
	{
		matrix_clear(A);
		matrix_clear(B);
	}
	return (M);
}
