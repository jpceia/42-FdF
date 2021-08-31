/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:33:58 by jceia             #+#    #+#             */
/*   Updated: 2021/08/31 22:06:12 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	grid_init(t_grid *grid)
{
	grid->data = NULL;
	grid->width = 0;
	grid->height = 0;
}

double	*grid_parse_line(char *line)
{
	double	*arr;
	char	**s_split;
	int		ncols;
	int		index;

	s_split = ft_split(line, ' ');
	if (!s_split)
	{
		ft_putendl_error("Error parsing line");
		exit(EXIT_FAILURE);
	}
	ncols = ft_strwc(line, ' ');
	arr = (double *)malloc(ncols * sizeof(*arr));
	if (!arr)
	{
		free(s_split);
		ft_putendl_error("Error assigning memory to array");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < ncols)
	{
		arr[index] = ft_atoi(s_split[index]);
		index++;
	}
	return (arr);
}

void	grid_append_line(t_grid *grid, char *line)
{
	double	**new_data;
	int		ncols;

	ncols = ft_strwc(line, ' ');
	if (grid->width == 0)
		grid->width = ncols;
	else if ((int)grid->width != ncols)
	{
		ft_putendl_error("Lines with different number of columns");
		exit(EXIT_FAILURE);
	}
	new_data = malloc((grid->height + 1) * sizeof(*new_data));
	if (!new_data)
	{
		ft_putendl_error("Error asigning memory to grid");
		exit(EXIT_FAILURE);
	}
	if (grid->data)
	{
		ft_memcpy(new_data, grid->data, grid->height * sizeof(*new_data));
		free(grid->data);
	}
	new_data[grid->height] = grid_parse_line(line);
	grid->height++;
}

void	grid_clear(t_grid *grid)
{
	int	index;

	index = 0;
	while (index < (int)grid->height - 1)
	{
		free(grid->data[index]);
		index++;
	}
	free(grid->data);
}

void	grid_parse_file(t_grid *grid, char *fname)
{
	char	*line;
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error opening file", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	grid_init(grid);
	while (ft_get_next_line(fd, &line) > 0)
		grid_append_line(grid, line);
	close(fd);
}

void	grid_print(t_grid	*grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)grid->height)
	{
		j = 0;
		while (j < (int)grid->width - 1)
		{
			ft_putnbr((int)grid->data[i][j]);
			ft_putchar('\t');
			j++;
		}
		ft_putnbr(grid->data[i][grid->width - 1]);
		ft_putchar('\n');
		i++;
	}
}
