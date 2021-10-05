/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_wu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:38:03 by jceia             #+#    #+#             */
/*   Updated: 2021/10/05 21:38:05 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// swaps two numbers
void fswap(float* a , float*b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

//returns integer part of a floating point number
int iPartOfNumber(float x)
{
    return (int)x;
}
  
//rounds off a number
int roundNumber(float x)
{
    return iPartOfNumber(x + 0.5) ;
}
  
//returns fractional part of a number
float fPartOfNumber(float x)
{
    if (x>0) return x - iPartOfNumber(x);
    else return x - (iPartOfNumber(x)+1); 
}

void	plot_wu_line(t_mlx *data, t_vec2D p, t_vec2D q, t_vec3D color)
{
	p.x = (int)p.x;
	p.y = (int)p.y;
	q.x = (int)q.x;
	q.y = (int)q.y;
    int steep = ft_iabs(q.y - p.y) > ft_iabs(q.x - p.x) ;
  
    // swap the co-ordinates if slope > 1 or we
    // draw backwards
    if (steep)
    {
        fswap(&p.x , &p.y);
        fswap(&q.x , &q.y);
    }
    if (p.x > q.x)
    {
        fswap(&p.x ,&q.x);
        fswap(&p.y ,&q.y);
    }
  
    //compute the slope
    float dx = q.x - p.x;
    float dy = q.y - p.y;
    float gradient = dy/dx;
    if (dx == 0.0)
        gradient = 1;
  
    int xpxl1 = p.x;
    int xpxl2 = q.x;
    float intersectY = p.y;
  
    // main loop
    if (steep)
    {
        int x;
        for (x = xpxl1 ; x <=xpxl2 ; x++)
        {
            // pixel coverage is determined by fractional
            // part of y co-ordinate
            plot_pixel(data, vec2D_create(intersectY, x), color, fPartOfNumber(intersectY));
            plot_pixel(data, vec2D_create(intersectY-1, x), color,1- fPartOfNumber(intersectY));
            intersectY += gradient;
        }
    }
    else
    {
        int x;
        for (x = xpxl1 ; x <=xpxl2 ; x++)
        {
            // pixel coverage is determined by fractional
            // part of y co-ordinate
            plot_pixel(data, vec2D_create(x, intersectY), color, fPartOfNumber(intersectY));
            plot_pixel(data, vec2D_create(x, intersectY-1), color, 1 -fPartOfNumber(intersectY));
            intersectY += gradient;
        }
    }
}
