/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:28:12 by jceia             #+#    #+#             */
/*   Updated: 2021/09/01 23:28:13 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef int	t_color;
typedef struct s_gradient
{
	int	color_start;
	int	color_end;
}	t_gradient;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);