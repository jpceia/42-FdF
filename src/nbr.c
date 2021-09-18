/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:06:13 by jceia             #+#    #+#             */
/*   Updated: 2021/09/10 10:56:52 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	get_nbr_unsigned(const char *str);

static float	get_nbr_frac(const char *str)
{
	int		index;
	int		base_size;
	float	x;

	if (ft_startswith(str, "0x"))
	{
		str += 2;
		base_size = 16;
	}
	else
		base_size = 10;
	if (!ft_isdigit(*str))
		return (0.0);
	x = get_nbr_unsigned(str);
	index = 0;
	while (ft_isdigit(str[index++]))
		x /= base_size;
	return (x);
}

float	get_nbr_unsigned(const char *str)
{
	char	N;
	char	**s_split;
	float	x;
	int		i;

	N = ft_strwc(str, ',');
	if (N > 1)
	{
		s_split = ft_split(str, ',');
		i = get_nbr_unsigned(s_split[0]);
		x = get_nbr_frac(s_split[1]);
		x = i + ft_isign(i) * x;
		ft_str_array_clear(s_split, N);
		return (x);
	}
	if (ft_startswith(str, "0x"))
		return ((float)ft_atoi_base(str + 2, "0123456789abcdef"));
	return ((float)ft_atoi(str));
}

float	get_nbr(const char *str)
{
	int		sgn;

	while (ft_isspace(*str))
		str++;
	sgn = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn = -1;
		str++;
	}
	return (sgn * get_nbr_unsigned(str));
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
	x -= i;
	if (x < 0)
		x = -x;
	s2 = ft_itoa((int)(1000000 * x));
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
