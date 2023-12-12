/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:31:33 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/12 18:28:55 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	msg_error(void)
{
	write(1, "error_load-fichier", 19);
	exit(0);
}

int	get_size_nb(char *ligne)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (ligne[i])
	{
		if ((ligne[i] >= '0' && ligne[i] <= '9') || (ligne[i] >= 'a'
				&& ligne[i] <= 'z') || (ligne[i] >= 'A' && ligne[i] <= 'Z'))
		{
			if (ligne[i + 1] == ' ' || ligne[i + 1] == '\n'
				|| ligne[i + 1] == '\0')
				value++;
		}
		i++ ;
	}
	free(ligne);
	return (value);
}

int	get_size(char *file_name, t_data *data)
{
	char	*line ;
	int		fd;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		msg_error();
	line = get_next_line(fd);
	if (!line)
		msg_error();
	data->width = get_size_nb(line);
	data->height = data->height + 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->height = data->height + 1;
		free(line);
	}
	close(fd);
	free(line);
	line = NULL ;
	return (0);
}

int	fild_tab( int *matrix, char *line, t_data *data)
{
	char	**str;
	int		i;

	i = 0 ;
	str = NULL;
	str = ft_split(line, ' ');
	while (str[i])
	{
		matrix[i] = ft_atoi(str[i]);
		if (matrix[i] > data->max)
			data->max = matrix[i];
		if (matrix[i] < data->min)
			data->min = matrix[i];
		free(str[i]);
		i++ ;
	}
	free(str);
	return (0);
}

void	read_file(char *file_name, t_data *data)
{
	char	*line;
	int		i;
	int		fd;

	get_size(file_name, data);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data ->matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fild_tab(data->matrix[i], line, data);
		free(line);
		line = NULL ;
		i++;
	}
	free(line);
	data->matrix[i] = NULL ;
	close(fd);
	get_next_line(fd);
}
