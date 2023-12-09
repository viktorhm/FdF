/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:46:05 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/08 14:09:30 by vharatyk         ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	zoom(float *x , float *y , float *x1 , float *y1 , t_data *data )
{
*x *= data->zoom;
*y *= data->zoom;
*x1 *= data->zoom;
*y1 *= data->zoom;

}
void isometrique(float *x , float *y , int z , t_data *data)
{
	*x = (*x - *y) * cos(0.6) ;
	*y = (*x + *y) * sin(data->angle)- z ;

}
void mouve(float *x1 , float *y1 , float *x2 , float *y2 ,t_data *data)
{
	*x1 += data->controlx; // gauche
	*y1 += data->controly; // haut
	*x2 += data->controlx;
	*y2 += data->controly;
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

	zoom(&x1 , &y1 , &x2 , &y2 , data);

	isometrique(&x1 , &y1 , z , data);
	isometrique(&x2 , &y2 , z1, data);

	if(z >= 3)
		data->color = create_trgb(00, 40, 0, 0);
	if(z1 >= 3)
		data->color = create_trgb(00, 40, 0, 0);
	else
		data->color = create_trgb(00, 100, 100, 100);

	mouve(&x1 , &y1 , &x2 , &y2 , data);

	x_step = x2 - x1 ;
	y_step = y2 - y1 ;

	max = MAX(abs(x_step),abs(y_step));
	x_step /= max;
	y_step /= max;

	while((int)(x1 - x2) || (int)(y1 - y2))
	{
		if(((int)x1 < data->wx  && (int)x1 > 0) && ((int)y1 < data->wy  && (int)y1 > 0))
			my_mlx_pixel_put(data , x1, y1, data->color);
		x1 += x_step;
		y1 += y_step;
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

