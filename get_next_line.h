/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:22:43 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/14 10:25:27 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

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

#endif
