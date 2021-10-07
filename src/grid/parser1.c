/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:33:58 by jceia             #+#    #+#             */
/*   Updated: 2021/10/07 23:20:00 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

void	strlst_clear(void *ptr)
{
	t_list	**lst;

	if (!ptr)
		return ;
	lst = (t_list **)ptr;
	ft_lstclear(lst, free);
}

t_list	*lst_parse_fd(int fd)
{
	t_list	*lst;
	char	*err_msg;
	char	*line;
	int		status;

	lst = NULL;
	err_msg = NULL;
	status = 1;
	while ((status > 0) && !err_msg)
	{
		status = ft_get_next_line(fd, &line);
		if (status == -1)
			err_msg = "Error reading the file";
		else if (status == 1)
			if (!ft_lstpush_back(&lst, line))
				err_msg = "Error loading the file to a linked list";
	}
	free(line);
	if (err_msg)
		return (clean_exit(&lst, err_msg, strlst_clear, 0));
	return (lst);
}

t_grid	*grid_parse_file(t_grid **grid, char *fname)
{
	int		fd;
	t_list	*lst;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (clean_exit(NULL, "Error opening file", NULL, 0));
	lst = lst_parse_fd(fd);
	if (!list_to_grid(lst, grid))
		return (NULL);
	if (close(fd) < 0)
		return (clean_exit(*grid, "Error closing file", grid_clear, 0));
	return (*grid);
}
