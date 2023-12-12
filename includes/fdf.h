/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:04:47 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/12 14:09:22 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_data
{
	int		width;
	int		height;
	int		**matrix;

	int		bits_per_pixel;
	int		line_length;
	int		endin;
	int		line;
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		zoom;
	int		z;
	int		max ;
	int		min ;
	int		wx;
	int		wy;
	int		controlx;
	int		controly;
	float	anglex;
	float	angley;
}			t_data;

typedef struct s_cord
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		z;
	int		z1;
	int		color ;
}	t_cord;

//#######get next line ########//
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_get_line(char *liste);
char	*stay_str(char *liste);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(int fd, char *liste);
void	ft_bzero(void *str, size_t count);

//######## read file ###########//
int		get_size_nb(char *ligne);
int		get_size(char *file_name, t_data *data);
int		fild_tab( int *matrix, char *line, t_data *data);
void	read_file(char *file_name, t_data *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str );
//####### drew ######## //
float	value_max(float a, float b);
void	init_struct_cord(t_cord *cord);
int		create_trgb(int t, int r, int g, int b);
int		color( t_cord *cord, t_data *data );
void	my_mlx_pixel_put(t_data *data, t_cord *cord);

void	zoom(t_cord *cord, t_data *data );
void	isometrique(t_cord *cord, t_data *data);
void	mouve(t_cord *cord, t_data *data);
void	bresenham(t_cord *cord, t_data *data);
void	four_arguemnts(t_cord *cord, int x, int y, t_data *data);

int		draw(t_data *data);
void	runing(t_cord *cord, t_data *data);

//####### main ####### //
void	init_struct(t_data *data);
int		ft_close(t_data *data);
void	control_base(int key, t_data *data);
int		control(int key, t_data *data);

int		event(t_data *data);
int		free_matrix(t_data *data);
int		main(int argc, char *argv[]);

#endif