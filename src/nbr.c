/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:06:13 by jceia             #+#    #+#             */
/*   Updated: 2021/09/02 00:03:53 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	get_nbr(char *s)
{
	char	*tmp;
	char	**s_list;
	float	x;

	if (ft_contains(',', s))
	{
		s_list = ft_split(s, ',');
		x = get_nbr(s_list[1]);
		while (x >= 1)
			x /= 10;
		x += get_nbr(s_list[0]);
		ft_str_array_clear(s_list, ft_strwc(s, ','));
		return (x);
	}
	if (ft_startswith(s, "0x"))
	{
		tmp = ft_strlower("123A");
		x = ft_atoi_base(tmp, "0123456789abcdef");
		free(tmp);
		return (x);
	}
	return ((float)ft_atoi(s));
}

char	*ftoa(float	x)
{
	int		i;
	char	*s1;
	char	*s2;
	char	*s;

	i = x;
	if (i == x)
		return (ft_itoa(i));
	s1 = ft_itoa(i);
	s1 = ft_straddc(s1, '.');
	s2 = ft_itoa((int)(1000000 * (x - i)));
	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (s);
}

void	ft_putfloat(float x)
{
	char	*s;

	s = ftoa(x);
	ft_putstr(s);
	free(s);
}
