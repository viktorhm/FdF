/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:42:56 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/12 13:58:45 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struct(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->matrix = NULL ;
	data->zoom = 20;
	data ->bits_per_pixel = 20 ;
	data->wx = 1700 ;
	data->wy = 900 ;
	data->controlx = 50 ;
	data->controly = 50 ;
	data->anglex = 0.8;
	data->angley = 0.8;
	data->max = 0 ;
	data->min = 0;
	data->z = 1 ;
}

int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	control_base(int key, t_data *data)
{
	if (key == 'w')
		data->controly -= 10;
	if (key == 'a')
		data->controlx -= 10;
	if (key == 's')
		data->controly += 10;
	if (key == 'd')
		data->controlx += 10;
	if (key == '-')
		data->zoom -= 2 ;
	if (key == '=')
		data->zoom += 2 ;
}

int	control(int key, t_data *data)
{
	control_base(key, data);
	if (key == ']')
		data->anglex += 0.10 ;
	if (key == '[')
		data->anglex -= 0.10 ;
	if (key == ',')
		data->angley += 0.10 ;
	if (key == '.')
		data->angley -= 0.10 ;
	if (key == 65307)
		ft_close(data);
	if (key == 'q')
		if (data->z > 1)
			data->z -= 1;
	if (key == 'e')
		data->z += 1;
	event(data);
	return (0);
}
