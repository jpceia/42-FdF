/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:33:58 by jceia             #+#    #+#             */
/*   Updated: 2021/10/06 07:24:30 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

static int	grid_append_line(int line_nr, int N, char *line, t_vec3D *arr)
{
	char	**s_split;
	int		index;

	if (ft_strwc(line, ' ') != N)
	{
		perror("Lines with different number of columns");
		return (-1);
	}
	s_split = ft_split(line, ' ');
	if (!s_split)
	{
		perror("Error parsing line");
		return (-1);
	}
	index = 0;
	while (index < N)
	{
		arr[index] = vec3D_create(index, line_nr, get_nbr(s_split[index]));
		index++;
	}
	ft_str_array_clear(s_split, N);
	return (0);
}

static void	list_to_grid(t_grid *grid, t_list *lst)
{
	int		status;
	int		line_nr;
	t_list	*node;

	grid_init(grid, ft_strwc(lst->content, ' '), ft_lstsize(lst));
	line_nr = 0;
	node = lst;
	status = 0;
	while (node && status != -1)
	{
		status = grid_append_line(
				line_nr, grid->width, node->content, grid->data[line_nr]);
		node = node->next;
		line_nr++;
	}
	ft_lstclear(&lst, free);
	if (status == -1)
	{
		grid_clear(grid);
		exit(EXIT_FAILURE);
	}
}

void	grid_parse_file(t_grid *grid, char *fname)
{
	t_list	*lst;
	char	*line;
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	lst = NULL;
	while (ft_get_next_line(fd, &line) > 0)
		ft_lstpush_back(&lst, line);
	free(line);
	close(fd);
	list_to_grid(grid, lst);
}
