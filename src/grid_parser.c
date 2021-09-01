/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:33:58 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 00:16:18 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	grid_append_line(float *arr, int N, char *line)
{
	char	**s_split;
	int		index;

	s_split = ft_split(line, ' ');
	if (!s_split)
	{
		ft_putendl_error("Error parsing line");
		exit(EXIT_FAILURE);
	}
	if (ft_strwc(line, ' ') != N)
	{
		ft_putendl_error("Lines with different number of columns");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < N)
	{
		arr[index] = get_nbr(s_split[index]);
		index++;
	}
	ft_str_array_clear(s_split, N);
}

int	protected_open(char *fname)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error opening file", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	fd_count_newlines(int fd)
{
	int		counter;
	char	*line;

	counter = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		counter++;
		free(line);
	}
	free(line);
	close(fd);
	return (counter);
}

void	grid_parse_file(t_grid *grid, char *fname)
{
	char	*line;
	int		fd;
	int		index;

	fd = protected_open(fname);
	ft_get_next_line(fd, &line);
	grid_init(grid, ft_strwc(line, ' '), fd_count_newlines(fd) + 1);
	fd = protected_open(fname);
	index = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		grid_append_line(grid->data[index++], grid->width, line);
		free(line);
	}
	free(line);
	close(fd);
}

void	grid_print(t_grid	*grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width - 1)
		{
			ft_putfloat(grid->data[i][j]);
			ft_putchar('\t');
			j++;
		}
		ft_putnbr(grid->data[i][grid->width - 1]);
		ft_putchar('\n');
		i++;
	}
}
