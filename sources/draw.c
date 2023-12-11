/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:46:05 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/11 13:32:23 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float value_max (float a , float b)
{
	if(a>b)
		return(a);
	return(b);
}


void init_struct_cord(t_cord *cord)
{
	cord->color =0xffffff ;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int color( t_cord *cord, t_data *data )
{

	return(create_trgb(00,100, 100, 100 ));

}
void	my_mlx_pixel_put(t_data *data, t_cord *cord)
{
	char	*dst;

	dst = data->addr + ((int)cord->y1 * data->line_length + (int)cord->x1 * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color(cord , data);
}

void	zoom(t_cord *cord, t_data *data )
{
if(data->zoom < 20);
cord->x1 *= data->zoom;
cord->y1 *= data->zoom;
cord->x2 *= data->zoom;
cord->y2 *= data->zoom;
cord->z *= data->zoom;
cord->z1 *= data->zoom;
data->min *= data->zoom;
data->max *= data->zoom;

}
void isometrique(t_cord *cord, t_data *data)
{

	cord->x1 = (cord->x1 - cord->y1) * cos(data->anglex) ;
	cord->y1 = (cord->x1 + cord->y1) * sin(data->angley)- cord->z ;

	cord->x2 = (cord->x2 - cord->y2) * cos(data->anglex) ;
	cord->y2 = (cord->x2 + cord->y2) * sin(data->angley)- cord->z1 ;
}
void mouve(t_cord *cord ,t_data *data)
{
	cord->x1 += data->controlx; // gauche
	cord->y1 += data->controly; // haut
	cord->x2 += data->controlx;
	cord->y2 += data->controly;
}


void laod_cord(t_cord *cord , float x1 , float y1 , float x2 , float y2)
{
	cord->x1 = x1 ;
	cord->y1 = y1 ;
	cord->x2 = x2 ;
	cord->y2 = y2 ;
	cord->color = create_trgb(00, 100, 100, 100);
}


void runing(float x1 , float y1 , float x2 , float y2 , t_data *data)
{
	t_cord cord ;

	laod_cord(&cord ,x1 ,y1 ,x2 ,y2);
	cord.z = data->matrix[(int)cord.y1][(int)cord.x1];
	cord.z1 = data->matrix[(int)cord.y2][(int)cord.x2];
	zoom(&cord, data);
	isometrique(&cord, data);
	mouve(&cord, data);
	bresenham(&cord ,data);

}

void bresenham(t_cord *cord , t_data *data)
{
	float x_step;
	float y_step ;
	int max ;
	x_step = cord->x2 - cord->x1 ;
	y_step = cord->y2 - cord->y1 ;

	max = value_max(abs(x_step),abs(y_step));
	x_step /= max;
	y_step /= max;

	while((int)(cord->x1 - cord->x2) || (int)(cord->y1 - cord->y2))
	{
		if(((int)cord->x1 < data->wx  && (int)cord->x1 > 0) && ((int)cord->y1 < data->wy  && (int)cord->y1 > 0))
			my_mlx_pixel_put(data , cord );
		cord->x1 += x_step;
		cord->y1 += y_step;
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
				runing(x , y , x+1 , y, data);
			if(y < data->height -1)
				runing(x , y , x , y+1 ,data);
			x++;
		}
	y++;
	}
	return(0);
}
