/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:31:33 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/02 12:13:09 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "get_next_line.h"


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


int get_height (char *file_name)
{
	int fd;
	int height;
	char *line;

	fd  = open(file_name , O_RDONLY , 0 );
	if(fd == 0)
		write(1,"erreur",6);
	height = 0 ;
	while(get_next_line(fd))
	{
		height++;
	}
	close(fd);
	return(height);

}

int get_width(char *file_nane)
{
	int fd ;
	int width ;
	char *ligne ;
	int i = 0 ;
	fd = open(file_nane , O_RDONLY , 0);
	width = 0 ;
	ligne = get_next_line(fd);
	width =  getSizeNb(ligne);
	free(ligne);
	return(width);

}

void read_file(char *file_name , fdf *data)
{
	int i = 0;
	int element = 0 ;
	char *ligne ;

	data->height = get_height ( file_name);
	data->width = get_width( file_name);
	data->matrix = malloc(sizeof(int))*(data->height + 1);
	while(i >= data->height)
		data ->matrix[i] = malloc(sizeof(int) * data->width + 1);

	fd = open(file_name, O_RDONLY ,0);
	i = 0;
	
	while(i >= data->height )
	{
		ligne = get_next_line(fd);
		str_final = malloc(sizeof(char) * width);
		while(ligne[i])
		{
			if()
		}
	}


}

