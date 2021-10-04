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


int	exit_handle(int keycode, t_mlx *data)
{
	(void)keycode;
	//printf("keycode: %d\n", keycode);
	mlx_data_clear(data);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_mlx *data)
{
	//printf("Key pressed: %d\n", keycode);
	if (keycode == K_DOWN_ARROW)
		data->pressed.down_arrow = 1;
	else if (keycode == K_UP_ARROW)
		data->pressed.up_arrow = 1;
	else if (keycode == K_LEFT_ARROW)
		data->pressed.left_arrow = 1;
	else if (keycode == K_RIGHT_ARROW)
		data->pressed.right_arrow = 1;
	else if (keycode == K_ESC)
	{
		mlx_data_clear(data);
		exit(EXIT_SUCCESS);
	}
	else
		return (0);
	return (1);
}

int	key_release(int keycode, t_mlx *data)
{
	//printf("Key released: %d\n", keycode);
	if (keycode == K_DOWN_ARROW)
		data->pressed.down_arrow = 0;
	else if (keycode == K_UP_ARROW)
		data->pressed.up_arrow = 0;
	else if (keycode == K_LEFT_ARROW)
		data->pressed.left_arrow = 0;
	else if (keycode == K_RIGHT_ARROW)
		data->pressed.right_arrow = 0;
	else
		return (0);
	return (1);
}

/*
 * Handles mouse events
 * * Scroll up	- button 4 -> Zoom IN
 * * Scroll down- button 5 -> Zoom OUT
 */
int	mouse_handle(int button, int x, int y, t_mlx *data)
{
	(void)x;
	(void)y;
	// printf("mouse: %d %d %d\n", button, x, y);
	if (button == 5) // zoom out
		data->cam.scaling /= 1.05;
	else if (button == 4) // zoom in
		data->cam.scaling *= 1.05;
	// printf("scaling factor: %f\n", data->cam.scaling);
	return (0);
}

void update_cam(t_camera *cam, const t_keys *pressed)
{
	if (pressed->left_arrow)
		cam->angles.yaw += 0.01;
	if (pressed->right_arrow)
		cam->angles.yaw -= 0.01;
	if (pressed->up_arrow)
		cam->angles.roll += 0.01;
	if (pressed->down_arrow)
		cam->angles.roll -= 0.01;
}

int mlx_render(void *ptr)
{
	t_mlx   *data;

	data = (t_mlx *)ptr;
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
	mlx_hook(data->win, 17, 0, exit_handle, data);
	mlx_hook(data->win, KEY_PRESS, M_KEY_PRESS, key_press, data);
	mlx_hook(data->win, KEY_RELEASE, M_KEY_RELEASE, key_release, data);
	//mlx_hook(data->win, MOUSE_PRESS, M_MOUSE_PRESS, mouse_pressed, data);
	//mlx_hook(data->win, MOUSE_RELEASE, M_MOUSE_RELEASE, mouse_released, data);
	mlx_loop_hook(data->mlx, mlx_render, data);
	mlx_mouse_hook(data->win, mouse_handle, data);
}
