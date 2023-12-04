/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:46:05 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/04 19:10:49 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/fdf.h"

#define MAX(a,b) (a>b ? a : b)
#define MOD(a)((a<0) ? -a : a)

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	zoom(float *x , float *y , float *x1 , float *y1 , t_data *data )
{
*x *= data->zoom;
*y *= data->zoom;
*x1 *= data->zoom;
*y1 *= data->zoom;

}
void isometrique(float *x , float *y , int z)
{
	*x= (*x-*y) * cos(0.8) ;
	*y = (*x + *y) * sin(0.8) -z ;

}

void bresenham(float x , float y , float x1 , float y1 ,t_data *data)
{
	float x_step;
	float y_step ;
	int max ;
	int z;
	int z1;

	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;


	isometrique(&x , &y , z);
	isometrique(&x1 , &y1 , z1);

	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;


	x_step = x1 - x ;
	y_step = y1 - y ;

	max = MAX(MOD(x_step),MOD(y_step));
	x_step /= max;
	y_step /= max;

	while((int)(x-x1) || (int)(y - y1))
	{
		//printf("%f\n" ,x);
		my_mlx_pixel_put(data , x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

int draw (t_data *data)
{
	int x = 0;
	int y = 0;
	while(data->height > y)
	{
		x= 0;
		while(data->width > x)
		{
			if(x < data->width -1)
				bresenham(x , y , x+1 , y, data);
			if(y < data->height -1)
				bresenham(x , y , x , y+1 ,data);
			x++;
		}
	y++;
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