/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:59:41 by jceia             #+#    #+#             */
/*   Updated: 2021/09/01 23:38:50 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "geom_utils.h"
# include "colors.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;


void	plot_pixel(t_data *data, t_point2D p, t_color color);
void    plot_line(t_data *data, t_line2D line, t_gradient g);

#endif