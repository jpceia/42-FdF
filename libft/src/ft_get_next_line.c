/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:10:07 by jceia             #+#    #+#             */
/*   Updated: 2021/10/07 22:45:01 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_next_line(int fd, char **line)
{
	int		nb;
	char	c;

	*line = ft_empty_string();
	if (fd < 0 || fd >= RLIMIT_NOFILE || !line)
		return (-1);
	if (!*line)
		return (-1);
	while (1)
	{
		nb = read(fd, &c, 1);
		if (nb <= 0 || c == '\n')
			break ;
		*line = ft_straddc(*line, c);
	}
	return (nb);
}
