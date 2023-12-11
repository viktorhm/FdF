/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:31:33 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/09 23:15:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


// gcc *.c -Lmlx-linux -lmlx_Linux -Imlx-linux -lXext -lX11 -lm

int getSizeNb(char *ligne  )
{
	int i = 0 ;
	int value = 0;
	while(ligne[i])
	{
	if((ligne[i]>='0' && ligne[i]<='9') || (ligne[i] >= 'a'
	&& ligne[i] <= 'z') || (ligne[i] >= 'A' && ligne[i] <= 'Z') )
		if(ligne[i+1]==' ' || ligne[i+1]=='\n' || ligne[i+1]== '\0')
			value++;
	i++;
	}
	return(value);
}


int get_size (char *file_name , t_data *data)
{
	int fd;
	char *line ;

	fd  = open(file_name , O_RDONLY , 0 );
	if(fd < 0)
	{
		write(1,"erreur_load-fichier",20);
		exit(0);
	}
	line = get_next_line(fd);
	data->width = getSizeNb(line);
	data->height = data->height + 1;
	while(get_next_line(fd))
		data->height = data->height + 1;
	close(fd);
	free(line);
	line = NULL ;
	return(0);
}


int fild_tab( int *matrix ,char *line ,t_data *data)
{
	char	**str;
	int 	i;

	i = 0 ;
	str = ft_split(line , ' ');
	while(str[i])
	{
		matrix[i] = ft_atoi(str[i]);
		if(matrix[i] > data->max)
			data->max = matrix[i];
		if(matrix[i] < data->min)
			data->min =matrix[i];
		free(str[i]);
		i++ ;
	}
	free(str);
	return(0);
}

void read_file(char *file_name , t_data *data)
{
	int i;
	int fd ;
	char *line;
	get_size( file_name, data );


	data->matrix = (int **)malloc(sizeof(int*) * (data->height+ 1));
	i = 0;
	while(i <= data->height)
		data ->matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));


	fd = open(file_name , O_RDONLY, 0);
	i = 0;
	while(i < data->height)
	{
		line = get_next_line(fd);
		fild_tab(data->matrix[i], line  , data);
		free(line);
		i++;
		//printf("{%d}",data->max);
	}
	data->matrix[i] = NULL ;
	close(fd);
}


