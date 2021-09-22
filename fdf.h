/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:03:39 by jceia             #+#    #+#             */
/*   Updated: 2021/09/21 17:12:05 by jceia            ###   ########.fr       */
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


typedef t_vec3D	t_rgb;
typedef	int	t_trgb;

int		create_trgb(t_rgb color);

t_rgb	color_interp(t_rgb c1, t_rgb c2, float t);

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
void	grid_print(t_grid	*grid);
float	grid_max(t_grid *grid, t_coord coord);
float	grid_min(t_grid *grid, t_coord coord);
void	grid_apply_transformation(t_grid *grid, t_matrix *M);

float	get_nbr(char *s);
void	ft_putfloat(float x);

/*
 * MLX Operations
 */
typedef	struct s_mouse
{
	float	x;
	float	y;
}	t_mouse;


typedef struct s_camera
{
	t_matrix	*transform;
	t_vec2D		screen_size;
	t_vec2D		offset;
	float		scaling;
}	t_camera;

void	camera_set_params(t_camera *cam, const t_grid *grid, int screen_width, int screen_height);

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

void	plot_pixel(t_mlx *data, float x, float y, t_rgb color);
void	grid_draw(t_mlx *data, const t_camera *cam, const t_grid *grid, t_rgb color);

#endif
