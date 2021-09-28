/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:03:39 by jceia             #+#    #+#             */
/*   Updated: 2021/09/29 00:45:39 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include "matrix.h"

# define WIN_TITLE  "42 - FDF"
# define WIN_WIDTH  640
# define WIN_HEIGHT 360

/*
 * Color
 */

typedef int		t_trgb;

int		create_trgb(t_vec3D color);

/*
 * Grid Utils
 */

typedef struct s_grid
{
	t_vec3D	**data;
	int		width;
	int		height;
}	t_grid;

void	grid_init(t_grid *grid, int width, int height);
t_grid	grid_clone(const t_grid *grid);
void	grid_clear(t_grid *grid);
void	grid_parse_file(t_grid *grid, char *fname);
float	grid_max(t_grid *grid, t_coord coord);
float	grid_min(t_grid *grid, t_coord coord);
void	grid_apply_transformation(t_grid *grid, t_matrix *M);

float	get_nbr(char *s);
void	ft_putfloat(float x);

/*
 * MLX Operations
 */
typedef struct s_mouse
{
	float	x;
	float	y;
}	t_mouse;

typedef struct s_camera
{
	t_vec3D			translation;
	t_euler_angles	euler_angles;
	t_vec2D			offset;
	float			scaling;
}	t_camera;

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
	t_camera	*cam;
}	t_mlx;

void	plot_pixel(t_mlx *data, float x, float y, t_vec3D color);
void	plot_line(t_mlx *data, t_vec2D p, t_vec2D q, t_vec3D color);
void	grid_draw(t_mlx *data, const t_camera *cam,
			const t_grid *grid, t_vec3D color);

#endif
