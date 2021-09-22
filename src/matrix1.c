/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:17:16 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 17:48:44 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_empty(int ncols, int nrows)
{
	t_matrix	*M;

	if (ncols <= 0 || nrows <= 0)
		return (NULL);
	M = (t_matrix *)malloc(sizeof(*M));
	if (!M)
		return (M);
	M->data = (float *)malloc(ncols * nrows * sizeof(*(M->data)));
	if (!M->data)
	{
		free(M);
		return (NULL);
	}
	return (M);
}

void	matrix_clear(t_matrix *M)
{
	if (M && M->data)
		free(M->data);
	if (M)
		free(M);
}

t_matrix	*matrix_zeros(int ncols, int nrows)
{
	int			idx;
	t_matrix	*M;

	M = matrix_empty(ncols, nrows);
	if (!M)
		return (NULL);
	idx = 0;
	while (idx < ncols * nrows)
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

void	matrix_print(t_matrix *M)
{
	int	i;
	int	j;

	if (!M)
		return ;
	i = 0;
	while (i < M->nrows)
	{
		j = 0;
		while (j < M->ncols - 1)
		{
			printf("%f\t", M->data[i * M->ncols + j]);
			j++;
		}
		printf("%f\n", M->data[i * M->ncols + j]);
		i++;
	}
}