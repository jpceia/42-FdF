/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:59:41 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 09:34:45 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "geom.h"
# include "color.h"

typedef	struct s_mouse
{
	float	x;
	float	y;
}	t_mouse;

typedef struct s_data
{
	void		*mlx;
	void		*win;

	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_mouse		*mouse;
}	t_data;

void	plot_pixel(t_data *data, t_point2D p, t_trgb trgb);

#endif