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

int	exit_handle(t_mlx *data)
{
	mlx_data_clear(data);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_mlx *data)
{
	if (keycode == K_DOWN_ARROW)
		data->pressed->down_arrow = 1;
	else if (keycode == K_UP_ARROW)
		data->pressed->up_arrow = 1;
	else if (keycode == K_LEFT_ARROW)
		data->pressed->left_arrow = 1;
	else if (keycode == K_RIGHT_ARROW)
		data->pressed->right_arrow = 1;
	else if (keycode == K_A)
		data->pressed->a = 1;
	else if (keycode == K_D)
		data->pressed->d = 1;
	else if (keycode == K_W)
		data->pressed->w = 1;
	else if (keycode == K_S)
		data->pressed->s = 1;
	else if (keycode == K_ESC)
		exit_handle(data);
	else
		return (0);
	return (1);
}

int	key_release(int keycode, t_mlx *data)
{
	if (keycode == K_DOWN_ARROW)
		data->pressed->down_arrow = 0;
	else if (keycode == K_UP_ARROW)
		data->pressed->up_arrow = 0;
	else if (keycode == K_LEFT_ARROW)
		data->pressed->left_arrow = 0;
	else if (keycode == K_RIGHT_ARROW)
		data->pressed->right_arrow = 0;
	else if (keycode == K_A)
		data->pressed->a = 0;
	else if (keycode == K_D)
		data->pressed->d = 0;
	else if (keycode == K_W)
		data->pressed->w = 0;
	else if (keycode == K_S)
		data->pressed->s = 0;
	else
		return (0);
	return (1);
}

/*
 * Handles mouse events
 * * Scroll up	- button 4 -> Zoom IN
 * * Scroll down- button 5 -> Zoom OUT
 */
int	mouse_press(int button, int x, int y, t_mlx *data)
{
	if (button == 1)
	{
		data->mouse->pressed = 1;
		data->mouse->pos = vec2d_create(x, y);
	}
	else if (button == 4)
		data->cam->scaling *= 1.05;
	else if (button == 5)
		data->cam->scaling /= 1.05;
	else
		return (0);
	return (1);
}

int	mouse_release(int button, int x, int y, t_mlx *data)
{
	if (button == 1)
	{
		data->mouse->pressed = 0;
		data->cam->offset = vec2d_add(data->cam->prev_offset,
				vec2d_subtract(vec2d_create(x, y),
					data->mouse->pos));
		data->cam->prev_offset = data->cam->offset;
	}
	else
		return (0);
	return (1);
}
