/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:22:33 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/12 16:10:04 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	event(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->wx, data->wy);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endin);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

int	free_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->matrix[i++]);
	free(data->matrix);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "NO_MAPS", 7);
		return (0);
	}
	init_struct(&data);
	read_file(argv[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.wx, data.wy, "FDF");
	event(&data);
	mlx_hook(data.win, 2, 1L << 0, control, &data);
	mlx_hook(data.win, 17, 1L << 5, ft_close, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	free_matrix(&data);
	return (0);
}
