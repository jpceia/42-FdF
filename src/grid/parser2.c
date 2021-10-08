/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:33:58 by jceia             #+#    #+#             */
/*   Updated: 2021/10/08 01:08:46 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3d	*grid_append_line(int line_nr, int N, char *line, t_vec3d *arr)
{
	char	**s_split;
	int		index;

	if (ft_strwc(line, ' ') != N)
		return (clean_exit(NULL, "Lines with different number of columns",
				NULL, 0));
	s_split = ft_split(line, ' ');
	if (!s_split)
		return (clean_exit(NULL, "Error parsing line", NULL, 0));
	index = 0;
	while (index < N)
	{
		arr[index] = vec3d_create(index, line_nr, get_nbr(s_split[index]));
		index++;
	}
	ft_str_array_clear(s_split, N);
	return (arr);
}

t_grid	*list_to_grid(t_list *lst, t_grid **grid)
{
	int		line_nr;
	t_list	*node;

	if (!grid_init(grid, ft_strwc(lst->content, ' '), ft_lstsize(lst)))
		return (NULL);
	line_nr = 0;
	node = lst;
	while (node)
	{
		grid_append_line(line_nr, (*grid)->width, node->content,
			(*grid)->data[line_nr]);
		if (!(*grid)->data[line_nr])
		{
			ft_lstclear(&lst, free);
			return (clean_exit(*grid, "Errow converting list to grid",
					grid_clear, 0));
		}
		node = node->next;
		line_nr++;
	}
	ft_lstclear(&lst, free);
	return (*grid);
}
