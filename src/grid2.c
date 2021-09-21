/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:47:52 by jceia             #+#    #+#             */
/*   Updated: 2021/09/18 21:46:51 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void	grid_print(t_grid *grid)
{
	int		i;
	int		j;
	t_vec3D	p;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			p = grid->data[i][j];
			ft_putfloat(p.x);
			ft_putchar(':');
			ft_putfloat(p.y);
			ft_putchar(':');
			ft_putfloat(p.z);
			ft_putchar('\t');
			j++;
		}
		p = grid->data[i][j];
		ft_putfloat(p.x);
		ft_putchar(':');
		ft_putfloat(p.y);
		ft_putchar(':');
		ft_putfloat(p.z);
		ft_putchar('\n');
		i++;
	}
}

void	grid_apply4x4(t_grid *grid, t_matrix4x4 M)
{
	int		i;
	int		j;
	t_vec3D	p;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			grid->data[i][j] = vec3D_apply4x4(M, grid->data[i][j]);
			j++;
		}
		i++;
	}
}

void	grid_apply3x3(t_grid *grid, t_matrix3x3 M)
{
	int		i;
	int		j;
	t_vec3D	p;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			grid->data[i][j] = vec3D_apply3x3(M, grid->data[i][j]);
			j++;
		}
		i++;
	}
}