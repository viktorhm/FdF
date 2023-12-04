/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:46:05 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/04 12:50:45 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/fdf.h"

#define MAX(a,b) (a>b ? a : b)
#define MOD(a)((a<0) ? -a : a)


void bresenham(float x , float y , float x1 , float y1 , t_data *data)
{
	float x_step;
	float y_step ;

	int max ;

	x_step = x1 - x ;
	y_step = y1 - y ;

	max = MAX(MOD(x_step),MOD(y_step));
	x_step /= max;
	y_step /= max;

	while((int)(x-x1) || (int)(y - y1))
	{
		printf("%f\n" ,x);
		mlx_pixel_put(data->mlx , data->win , x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}



// int swap(int *start , int *end)
// {
// int tmp = 0 ;
// tmp = *start ;
// *start = *end ;
// *end = tmp ; 

// }


// void	draw_line(int x_start , int y_start , int x_end  , int y_end , fdf *fdf)
// {

// 	int dx;
// 	int dy;
// 	dx = x_end - x_start;
// 	dy  = y_end - y_start;
// 	int value = 0 ;

// 	if(abs(dx) > abs(dy))
// 	{
// 		if(x_start > x_end)
// 		{
// 			swap(&x_start , &x_end);
// 			swap(&y_start , &y_end) ;
// 			dx = -dx;
// 			dy = -dy;
// 		}
// 		if(dy < 0)
// 		{
// 			value = -1 ;
// 			dy = -dy ;
// 		}
// 		int x = 0;
// 		while (x <= x_end)
// 		{
// 			if(x >= 0 && x < fdf->width && y >= 0 && y < fdf->height)
// 			{
// 				mlx_pixel_put()
// 			}
// 		}
		
// 	}
// }