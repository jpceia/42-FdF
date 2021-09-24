/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/09/22 17:42:31 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	grid_apply_transformation(t_grid *grid, t_matrix *M)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			grid->data[i][j] = matrix_homogenous_mul_vec3D(M, grid->data[i][j]);
			j++;
		}
		i++;
	}
}
