/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:31:33 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/01 16:26:32 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "get_next_line.h"


int getSizeNb(char *ligne)
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

int get_white(char *file_mane)
{
	int fd ;
	int width ;
	char *ligne ;
	int i = 0 ;
	fd = open(file_mane , O_RDONLY , 0);
	width = 0 ;
	ligne = get_next_line(fd);
	width =  getSizeNb(ligne);
	free(ligne);
	return(width);

}

void read_file(char *file_name , fdf *data)
{

	data->height = get_height ( file_name);
	data->width = get_white( file_name);

	while( hei)
}
