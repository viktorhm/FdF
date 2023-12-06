/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:46:05 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/06 22:34:49 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/fdf.h"

#define MAX(a,b) (a>b ? a : b)


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
	*x = (*x - *y) * cos(0.8) ;
	*y = (*x + *y) * sin(0.8)- z ;

}

void bresenham(float x1 , float y1 , float x2 , float y2 ,t_data *data)
{
	float x_step;
	float y_step ;
	int max ;
	int z;
	int z1;

	z = data->matrix[(int)y1][(int)x1];
	z1 = data->matrix[(int)y2][(int)x2];

	x1 *= data->zoom;
	y1 *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;

	isometrique(&x1 , &y1 , z);
	isometrique(&x2 , &y2 , z1);

	x1 += data->controlx; // gauche
	y1 += data->controly; // haut
	x2 += data->controlx;
	y2 += data->controly;

	x_step = x2 - x1 ;
	y_step = y2 - y1 ;

	max = MAX(abs(x_step),abs(y_step));
	x_step /= max;
	y_step /= max;

	while((int)(x1 - x2) || (int)(y1 - y2))
	{
		if( (x1 < data->wx  && x1 > 0) && (y1 < data->wx  && y1 > 0))
			my_mlx_pixel_put(data , x1, y1, data->color);
		x1 += x_step;
		y1 += y_step;
	}
}


// void bresenham(t_data *data)
// {

// 	int x1 = 10 ;
// 	int y1 = 10 ;
// 	int x2 = 300 ;
// 	int y2 = 300 ;

// 	int ex = abs(x2 - x1);
// 	int ey = abs (y2 - y1);
// 	int i = 0 ;
// 	int Xincr =1;
// 	int Yincr =1;
// 	int dx = 2 * ex ;
// 	int dy = 2 * ey ;
// 	int Dx = ex ;
// 	int Dy = ey ;

//  	x1 *= data->zoom;
//  	y1 *= data->zoom;
//  	x2 *= data->zoom;
//  	y2 *= data->zoom;

// 	if( x1 > x2)
// 		Xincr = -1;
// 	if(y1> y2)
// 		Yincr = -1;

// 	if(Dx > Dy)
// 	{
// 		while (i <= Dx)
// 		{
// 				my_mlx_pixel_put(data , x1, y1, data->color);
// 				i++;
// 				x1 += Xincr;
// 				ey -= dy;

// 			if(ex < 0)
// 			{
// 				y1 += Yincr ;
// 				ex += dx;
// 			}
// 		}
// 	}
// 	if(Dy > Dx)
// 	{
// 		while (i <= Dy)
// 		{
// 				my_mlx_pixel_put(data , x1, y1, data->color);
// 				i++;
// 				y1 += Yincr;
// 				ey -= dx;

// 			if(ey < 0)
// 			{
// 				x1 += Xincr ;
// 				ey += dy;
// 			}
// 		}
// 	}

// }

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