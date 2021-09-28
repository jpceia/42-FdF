/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:30:19 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 17:38:36 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_bool	check_matrix_nrows(int nrows, int _nrows)
{
	if (nrows != _nrows)
	{
		ft_putendl_error("Row number mismatch: ");
		ft_putnbr_error(nrows);
		ft_putstr_error("!=");
		ft_putnbr_error(_nrows);
		ft_putchar_error('\n');
	}
	return (nrows == _nrows);
}

t_bool	check_matrix_ncols(int ncols, int _ncols)
{
	if (ncols != _ncols)
	{
		ft_putendl_error("Column number mismatch: ");
		ft_putnbr_error(ncols);
		ft_putstr_error("!=");
		ft_putnbr_error(_ncols);
		ft_putchar_error('\n');
	}
	return (ncols == _ncols);
}
