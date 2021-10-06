/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:17:16 by jceia             #+#    #+#             */
/*   Updated: 2021/10/06 07:02:40 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_empty(int nrows, int ncols)
{
	t_matrix	*M;

	if (nrows <= 0 || ncols <= 0)
		return (NULL);
	M = (t_matrix *)malloc(sizeof(*M));
	M->nrows = nrows;
	M->ncols = ncols;
	if (!M)
		return (M);
	M->data = (float *)malloc(nrows * ncols * sizeof(*(M->data)));
	if (!(M->data))
	{
		free(M);
		return (NULL);
	}
	return (M);
}

void	matrix_clear(t_matrix *M)
{
	if (M)
	{
		if (M->data)
			free(M->data);
		free(M);
		M = NULL;
	}
}

t_matrix	*matrix_zeros(int nrows, int ncols)
{
	int			idx;
	t_matrix	*M;

	M = matrix_empty(nrows, ncols);
	if (!M)
		return (NULL);
	idx = 0;
	while (idx < nrows * ncols)
		M->data[idx++] = 0;
	return (M);
}

float	matrix_at(t_matrix *A, int i, int j)
{
	if (!A)
	{
		ft_putendl_error("NULL ptr");
		return (NAN);
	}
	if (i < 0 || i >= A->nrows)
	{
		ft_putendl_error("Row index outside range");
		return (NAN);
	}
	if (j < 0 || j >= A->ncols)
	{
		ft_putendl_error("Column index outside range");
		return (NAN);
	}
	return (A->data[i * A->ncols + j]);
}
