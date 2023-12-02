#ifndef FDF_H
# define FHF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	int	width;
	int	height;
	int	**matrix;

}fdf;



//#######get next line ########//
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		seach_new_line(char *liste );
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_get_line(char *liste);
char	*stay_str(char *liste);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(int fd, char *liste);
void	ft_bzero(void *str, size_t count);

//######## read file ###########//
void	read_file(char *file_name , fdf *data);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str );

#endif