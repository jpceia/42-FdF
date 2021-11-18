/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mlx_utils.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jceia <jceia@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/09/01 20:28:58 by jceia			 #+#	#+#			 */
/*   Updated: 2021/09/02 00:22:11 by jceia			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "libft.h"

/**
 * @brief Function to clean up and exit the program.
 * 
 * @param 	data	the variable to clean up.
 * @param 	msg		the error message to print.
 * @param 	del		the clean up function to call.
 * @param 	do_exit	if the program should exit.
 * @return	void*	always returns NULL
 */
void	*clean_exit(void *data, char *msg, void (*del)(void *), int do_exit)
{
	perror(msg);
	if (del)
		del(data);
	if (do_exit)
		exit(EXIT_FAILURE);
	return (NULL);
}

/**
 * @brief	Calculates the color grid structure, based on the height of the
 * 			map and the color scheme (consisting of two colors).
 * 
 * @param color_grid	the color grid structure to fill.
 * 						(the structure is allocated by the function)
 * @param	grid		the height map.
 * @param	colors		an array of two colors.
 * @return t_grid*		the color grid structure.
 * 						NULL if an error occurred.
 */
t_grid	*color_grid_init(t_grid **color_grid, const t_grid *grid,
		const t_vec3d colors[2])
{
	int		i;
	int		j;
	float	d;
	float	z[2];

	if (!grid_init(color_grid, grid->width, grid->height))
		return (NULL);
	i = 0;
	z[0] = grid_min(grid, COORD_Z);
	z[1] = grid_max(grid, COORD_Z);
	d = fmaxf(0.25 * fmaxf(grid->width, grid->height), z[1] - z[0]);
	(*color_grid)->width = grid->width;
	(*color_grid)->height = grid->height;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			(*color_grid)->data[i][j] = vec3d_interpolate(
					colors[0], colors[1], (grid->data[i][j].z - z[0]) / d);
			j++;
		}
		i++;
	}
	return (*color_grid);
}

/**
 * @brief	Initializes the mlx data structure.
 * @note	If the allocation fails, the program will exit.
 * 
 * @param	data	reference to the mlx data structure, allocated by the caller.
 * @param	args	arguments passed to the program.
 * @return	t_mlx*	pointer to the initialized mlx data structure. 
 */
t_mlx	*mlx_data_init(t_mlx *data, const t_args *args)
{
	if (!grid_parse_file(args->fname, &(data->grid)))
		clean_exit(data, "Failed to parse grid from file", mlx_data_clear, 1);
	if (!camera_init(&(data->cam), data->grid, args->screen_size))
		clean_exit(data, "Failed setting up the camera", mlx_data_clear, 1);
	data->mlx = mlx_init();
	data->width = args->screen_size.x;
	data->height = args->screen_size.y;
	if (!color_grid_init(&(data->color_grid), data->grid, args->colors))
		clean_exit(data, "Failed setting up color-grid", mlx_data_clear, 1);
	data->win = mlx_new_window(data->mlx, data->width,
			data->height, args->title);
	if (!data->win)
		clean_exit(data, "Failed to create a new window", mlx_data_clear, 1);
	data->pressed = (t_keys *)ft_calloc(1, sizeof(*data->pressed));
	if (!data->pressed)
		clean_exit(data, "Failed allocating memory", mlx_data_clear, 1);
	data->mouse = (t_mouse *)ft_calloc(1, sizeof(*data->mouse));
	if (!data->mouse)
		clean_exit(data, "Failed allocating memory", mlx_data_clear, 1);
	return (data);
}

/**
 * @brief	Cleans up the mlx data structure.
 * 
 * @param	ptr	pointer to the mlx data structure.
 */
void	mlx_data_clear(void *ptr)
{
	t_mlx	*data;

	if (!ptr)
		return ;
	data = (t_mlx *)ptr;
	grid_clear(data->grid);
	grid_clear(data->color_grid);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	if (data->cam)
		free(data->cam);
	if (data->mouse)
		free(data->mouse);
	if (data->pressed)
		free(data->pressed);
	free(data);
}
