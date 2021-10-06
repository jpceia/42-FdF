/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:30:19 by jceia             #+#    #+#             */
/*   Updated: 2021/10/06 07:01:06 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_bool	check_matrix_nrows(int nrows, int _nrows)
{
	if (nrows != _nrows)
	{
		perror("Row number mismatch");
		return (false);
	}
	return (true);
}

t_bool	check_matrix_ncols(int ncols, int _ncols)
{
	if (ncols != _ncols)
	{
		perror("Column number mismatch");
		return (false);
	}
	return (true);
}
