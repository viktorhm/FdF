/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:31:33 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/07 14:59:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "get_next_line.h"

// gcc *.c -Lmlx-linux -lmlx_Linux -Imlx-linux -lXext -lX11 -lm

int getSizeNb(char *ligne  )
{
	int i = 0 ;
	int value = 0;
	while(ligne[i])
	{
	if(ligne[i]>='0' && ligne[i]<='9')
		if(ligne[i+1]==' ' || ligne[i+1]=='\n' || ligne[i+1]== '\0')
			value++;
	i++;
	}
	return(value);
}


int get_size (char *file_name , int *height , int *width)
{
	int fd;
	char *line ;
	*height= 0;
	*width = 0;

	fd  = open(file_name , O_RDONLY , 0 );
	if(fd < 0)
	{
		write(1,"erreur",6);
		exit(0);
	}
	line = get_next_line(fd);
	*width = getSizeNb(line);
	*height = *height+1;
	free(line);
	line = NULL ;
	while(get_next_line(fd))
	{
		// test a rajouter
		*height=*height+1;
	}
	close(fd);

}


int fild_tab( int *matrix ,char *line ,int min , int max )
{
	char	**str;
	int 	i;

	max = 0;
	min = 0;
	i = 0 ;
	str = ft_split(line , ' ');
	while(str[i])
	{
		matrix[i] = ft_atoi(str[i]);

		if(min < matrix[i])
			min = matrix[i] ;
		if(max > matrix[i])
			max = matrix[i] ;
		free(str[i]);
		i++ ;
	}

}

void read_file(char *file_name , t_data *data)
{
	int i;
	int fd ;
	char *line;
	get_size( file_name, &data->height, &data->width );


	data->matrix = (int **)malloc(sizeof(int*) * (data->height+ 1));
	i = 0;
	while(i <= data->height)
		data ->matrix[i++] = (int*)malloc(sizeof(int) * (30 + 1));


	fd = open(file_name , O_RDONLY, 0);
	i = 0;
	while(i < data->height)
	{
		line = get_next_line(fd);
		fild_tab(data->matrix[i], line  , data->min , data->max);
		free(line);
		i++;
		//printf("{%d}",data->max);
	}
	data->matrix[i] = NULL ;

}

