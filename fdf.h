/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:03:39 by jceia             #+#    #+#             */
/*   Updated: 2021/09/17 11:35:27 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>

# define WIN_TITLE  "42 - FDF"
# define WIN_WIDTH  640
# define WIN_HEIGHT 360

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef enum e_coord
{
	COORD_X,
	COORD_Y,
	COORD_Z
}	t_coord;

typedef struct s_vec3D
{
	float	x;
	float	y;
	float	z;
}	t_vec3D;

typedef struct s_vec2D
{
	float	x;
	float	y;
}	t_vec2D;

/*
 * vec3D
 */
t_vec3D	vec3D_create(float x, float y, float z);
t_vec3D	vec3D_origin(void);
t_vec3D	vec3D_subtract(t_vec3D q, t_vec3D p);
t_vec3D	vec3D_add(t_vec3D p, t_vec3D v);
float	vec3D_coord(t_vec3D p, t_coord coord);

t_vec3D	vec3D_scalar_mul(t_vec3D v, float l);
t_vec3D	vec3D_normalize(t_vec3D v);
t_vec3D	vec3D_cross_product(t_vec3D u, t_vec3D v);
t_vec3D	vec3D_elementwise_product(t_vec3D u, t_vec3D v);
t_vec3D	vec3D_interpolate(t_vec3D p, t_vec3D q, float t);

float	vec3D_dot_product(t_vec3D u, t_vec3D v);
float	vec3D_norm_squared(t_vec3D v);
float	vec3D_norm(t_vec3D v);
float	vec3D_angle(t_vec3D u, t_vec3D v);

/*
 * vec2D
 */
t_vec2D	vec2D_create(float x, float y);
t_vec2D	vec2D_origin(void);
t_vec2D	vec2D_subtract(t_vec2D q, t_vec2D p);
t_vec2D	vec2D_add(t_vec2D p, t_vec2D v);
float	vec2D_coord(t_vec2D p, t_coord coord);

t_vec2D	vec2D_scalar_mul(t_vec2D v, float l);
t_vec2D	vec2D_normalize(t_vec2D v);
float	vec2D_cross_product(t_vec2D u, t_vec2D v);
t_vec2D	vec2D_elementwise_product(t_vec2D u, t_vec2D v);
t_vec2D	vec2D_interpolate(t_vec2D p, t_vec2D q, float t);

float	vec2D_dot_product(t_vec2D u, t_vec2D v);
float	vec2D_norm_squared(t_vec2D v);
float	vec2D_norm(t_vec2D v);
float	vec2D_angle(t_vec2D u, t_vec2D v);

/*
 * Color
 */


typedef t_vec3D	t_rgb;
typedef	int	t_trgb;

int		create_trgb(t_rgb color);

t_rgb	color_interp(t_rgb c1, t_rgb c2, float t);

/*
 * Matrices
 */
typedef float t_matrix4x4[4][4];
typedef float t_matrix3x3[3][3];

void	matrix4x4_mul(t_matrix4x4 A, t_matrix4x4 B, t_matrix4x4 M);
void	matrix4x4_affine(t_matrix3x3 A, t_vec3D translation, t_matrix4x4 M);
t_vec3D	vec3D_apply(t_matrix4x4 M, t_vec3D p);

void	matrix3x3_rotationX(float theta, t_matrix3x3 M);
void	matrix3x3_rotationY(float theta, t_matrix3x3 M);
void	matrix3x3_rotationZ(float theta, t_matrix3x3 M);
void	matrix3x3_scalar_scaling(float s, t_matrix3x3 M);
void	matrix3x3_scaling(float s_x, float s_y, float s_z, t_matrix3x3 M);
void	matrix3x3_mul(t_matrix3x3 A, t_matrix3x3 B, t_matrix3x3 M);
void	matrix3x3_print(t_matrix3x3 M);
void	matrix4x4_print(t_matrix4x4 M);

typedef	struct s_mouse
{
	float	x;
	float	y;
}	t_mouse;


typedef struct s_camera
{
	t_vec3D	orig;
	t_vec3D	direction;
	t_vec3D	v_x;
	t_vec3D	v_y;
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
}	t_data;

void	plot_pixel(t_data *data, float x, float y, t_rgb color);

typedef struct s_grid
{
	t_vec3D	**data;
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
