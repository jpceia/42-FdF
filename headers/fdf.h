/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:03:39 by jceia             #+#    #+#             */
/*   Updated: 2021/10/08 01:18:41 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include "matrix.h"

# define WIN_TITLE		"42 - FDF"
# define WIN_WIDTH		1080
# define WIN_HEIGHT		720

# define K_LEFT_ARROW	65361
# define K_RIGHT_ARROW	65363
# define K_UP_ARROW		65362
# define K_DOWN_ARROW	65364
# define K_ESC			65307
# define K_A			97
# define K_D			100
# define K_W			119
# define K_S			115

/*
 * X11 Events
 */
# define KEY_PRESS		02
# define KEY_RELEASE	03
# define BUTTON_PRESS	04
# define BUTTON_RELEASE 05
# define DESTROY_NOTIFY	17

/*
 * X11 Masks
 */
# define M_NO_EVENT			0L
# define M_KEY_PRESS		1L
# define M_KEY_RELEASE		2L
# define M_BUTTON_PRESS 	4L
# define M_BUTTON_RELEASE	8L

/*
 * Color
 */

int			create_trgb(t_vec3d color);

/*
 * Grid Utils
 */

typedef struct s_grid
{
	t_vec3d	**data;
	int		width;
	int		height;
}	t_grid;

t_grid		*grid_init(t_grid **grid, int width, int height);
t_grid		*grid_clone(const t_grid *grid);
void		grid_clear(void *ptr);
t_grid		*grid_parse_file(t_grid **grid, char *fname);
t_grid		*list_to_grid(t_list *lst, t_grid **grid);
float		grid_max(const t_grid *grid, t_coord coord);
float		grid_min(const t_grid *grid, t_coord coord);
t_grid		*grid_apply_transformation(t_grid *grid, t_matrix *m);

/*
 * Utils
 */
float		get_nbr(char *s);
void		ft_putfloat(float x);

/*
 * MLX Operations
 */
typedef struct s_mouse
{
	t_vec2d			pos;
	unsigned int	pressed;
}	t_mouse;

typedef struct s_camera
{
	t_vec3d	translation;
	t_vec3d	angles;
	t_vec2d	prev_offset;
	t_vec2d	offset;
	float	z_scaling;
	float	scaling;
}	t_camera;

t_matrix	*camera_transform(const t_camera *cam);

typedef struct s_args
{
	char	*title;
	char	*fname;
	t_vec2d	screen_size;
	t_vec3d	colors[2];
}	t_args;

typedef struct s_keys
{
	unsigned int	left_arrow	:1;
	unsigned int	right_arrow :1;
	unsigned int	up_arrow	:1;
	unsigned int	down_arrow	:1;
	unsigned int	a			:1;
	unsigned int	d			:1;
	unsigned int	w			:1;
	unsigned int	s			:1;
}	t_keys;

typedef struct s_mlx
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
	t_grid		*grid;
	t_grid		*color_grid;
	t_keys		*pressed;
}	t_mlx;

void		plot_pixel(t_mlx *data, t_vec2d p, t_vec3d color);
void		plot_line(t_mlx *data, t_vec2d p[2], t_vec3d color[2]);
void		grid_draw(t_mlx *data);

void		mlx_data_clear(void *ptr);
void		*clean_exit(void *data, char *msg, void (*del)(void *),
				int do_exit);
t_camera	*camera_init(t_camera **cam, const t_grid *grid,
				t_vec2d screen_size);
t_mlx		*mlx_data_init(t_mlx *data, const t_args *args);

void		mlx_add_hooks(t_mlx *data);
int			mlx_render(void *ptr);

int			exit_handle(t_mlx *data);
int			key_press(int keycode, t_mlx *data);
int			key_release(int keycode, t_mlx *data);
int			mouse_press(int button, int x, int y, t_mlx *data);
int			mouse_release(int button, int x, int y, t_mlx *data);

#endif
