/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:30:34 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/21 08:49:35 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_cord *cord, t_data *data )
{
	cord->x1 *= data->zoom;
	cord->y1 *= data->zoom;
	cord->x2 *= data->zoom;
	cord->y2 *= data->zoom;
	cord->z *= data->zoom / data->z;
	cord->z1 *= data->zoom / data->z;
}

void	isometrique(t_cord *cord, t_data *data)
{
	double		tx1;
	double		tx2;

	tx1 = cord->x1;
	tx2 = cord->x2;
	cord->x1 = tx1 * cos(data->angley) - cord->y1 * sin(data->anglex);
	cord->y1 = (tx1 * sin(data->anglex) + cord->y1 * cos(data->anglex))
		- cord->z;
	cord->x2 = tx2 * cos(data->angley) - cord->y2 * sin(data->anglex);
	cord->y2 = (tx2 * sin(data->anglex) + cord->y2 * cos(data->anglex))
		- cord->z1;
}

void	mouve(t_cord *cord, t_data *data)
{
	cord->x1 += data->controlx;
	cord->y1 += data->controly;
	cord->x2 += data->controlx;
	cord->y2 += data->controly;
}

void	bresenham(t_cord *cord, t_data *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = cord->x2 - cord->x1 ;
	y_step = cord->y2 - cord->y1 ;
	max = value_max(abs((int)x_step), abs((int)y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(cord->x1 - cord->x2) || (int)(cord->y1 - cord->y2))
	{
		if (((int)cord->x1 < data->wx && (int)cord->x1 > 0)
			&& ((int)cord->y1 < data->wy && (int)cord->y1 > 0))
			my_mlx_pixel_put(data, cord);
		cord->x1 += x_step;
		cord->y1 += y_step;
	}
}

void	four_arguemnts(t_cord *cord, int x, int y, t_data *data)
{
	if (x < data->width - 1)
	{
		cord->x1 = x;
		cord->y1 = y;
		cord->x2 = x + 1;
		cord->y2 = y;
		cord->color = create_trgb(00, 100, 100, 100);
		runing(cord, data);
	}
	if (y < data->height - 1)
	{
		cord->x1 = x;
		cord->y1 = y;
		cord->x2 = x;
		cord->y2 = y + 1;
		cord->color = create_trgb(00, 100, 100, 100);
		runing(cord, data);
	}
}
