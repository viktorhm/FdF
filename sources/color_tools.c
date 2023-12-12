/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:27:05 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/12 13:33:01 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	value_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	init_struct_cord(t_cord *cord)
{
	cord ->color = 0xffffff ;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color( t_cord *cord, t_data *data )
{
	int	r;
	int	g;
	int	b;

	r = 255;
	g = 255;
	b = 255;
	if (data->max > 1)
	{
		g = (cord->z / data->zoom) * 255 / data->max;
		b = (cord->z1 / data->zoom) * 255 / data->max;
	}
	return (create_trgb(00, r, g, b));
}

void	my_mlx_pixel_put(t_data *data, t_cord *cord)
{
	char	*dst;

	dst = data->addr + ((int)cord ->y1 * data ->line_length
			+ (int)cord ->x1 * (data ->bits_per_pixel / 8));
	*(unsigned int *)dst = color(cord, data);
}
