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
	float 	anglex;
	float	angley;
}			t_data;

typedef struct s_cord
{
	float x1;
	float y1;
	float x2;
	float y2;
	int	z;
	int z1;
	int color ;
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
void	read_file(char *file_name , t_data *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str );

//####### drew ######## //
void bresenham(t_cord *cord,t_data *data);
int draw (t_data *data );
void zoom(t_cord *cord, t_data *data );
#endif
