/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   hooks.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jceia <jceia@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/09/29 01:41:34 by jceia			 #+#	#+#			 */
/*   Updated: 2021/09/29 02:26:13 by jceia			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	update_cam(t_camera *cam, const t_keys *pressed)
{
	if (pressed->left_arrow)
		cam->angles.z += 0.01;
	if (pressed->right_arrow)
		cam->angles.z -= 0.01;
	if (pressed->up_arrow)
		cam->angles.x += 0.01;
	if (pressed->down_arrow)
		cam->angles.x -= 0.01;
	if (pressed->w)
		cam->z_scaling *= 1.01;
	if (pressed->s)
		cam->z_scaling /= 1.01;
}

int	mlx_render(void *ptr)
{
	int		x;
	int		y;
	t_vec2D	p;
	t_mlx	*data;

	data = (t_mlx *)ptr;
	if (data->mouse.pressed)
	{
		mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
		p.x = x;
		p.y = y;
		data->cam.offset = vec2D_add(
				data->cam.prev_offset,
				vec2D_subtract(p, data->mouse.pos));
	}
	update_cam(&(data->cam), &(data->pressed));
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
	grid_draw(data, &data->cam, &data->grid, vec3D_create(1.0, 1.0, 1.0));
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (1);
}

void	mlx_add_hooks(t_mlx *data)
{
	mlx_hook(data->win, DESTROY_NOTIFY, M_NO_EVENT, exit_handle, data);
	mlx_hook(data->win, KEY_PRESS, M_KEY_PRESS, key_press, data);
	mlx_hook(data->win, KEY_RELEASE, M_KEY_RELEASE, key_release, data);
	mlx_hook(data->win, BUTTON_PRESS, M_BUTTON_PRESS, mouse_press, data);
	mlx_hook(data->win, BUTTON_RELEASE, M_BUTTON_RELEASE, mouse_release, data);
	mlx_loop_hook(data->mlx, mlx_render, data);
}
