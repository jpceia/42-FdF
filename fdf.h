/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:03:39 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 11:09:21 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include "mlx_utils.h"

# define WIN_TITLE  "42 - FDF"
# define WIN_WIDTH  640
# define WIN_HEIGHT 360

typedef struct s_grid
{
	t_point3D	**data;
	int		width;
	int		height;
}	t_grid;


void	grid_init(t_grid *grid, int width, int height);
void	grid_clear(t_grid *grid);
void	grid_parse_file(t_grid *grid, char *fname);
void	grid_print(t_grid	*grid);
float	grid_max(t_grid *grid, t_coord coord);
float	grid_min(t_grid *grid, t_coord coord);
float	get_nbr(char *s);
void	ft_putfloat(float x);

#endif
