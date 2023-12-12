/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:46:05 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/12 13:58:15 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	runing(t_cord *cord, t_data *data)
{
	cord->z = data->matrix[(int)cord->y1][(int)cord->x1];
	cord->z1 = data->matrix[(int)cord->y2][(int)cord->x2];
	zoom(cord, data);
	isometrique(cord, data);
	mouve(cord, data);
	bresenham(cord, data);
}

int	draw(t_data *data)
{
	t_cord	cord;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->height > y)
	{
		x = 0;
		while (data->width > x)
		{
			four_arguemnts(&cord, x, y, data);
			x++;
		}
		y++;
	}
	return (0);
}
