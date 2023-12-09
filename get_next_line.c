/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:11:56 by vharatyk          #+#    #+#             */
/*   Updated: 2023/12/09 15:38:24 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

char	*get_next_line(int fd)
{
	static char	*liste = NULL;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0)
	{
		free(liste);
		return (0);
	}
	liste = read_line(fd, liste);
	if (!liste)
	{
		free(liste);
		return (NULL);
	}
	line = ft_get_line(liste);
	liste = stay_str(liste);
	return (line);
}

char	*stay_str(char *liste)
{
	char	*remains;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (liste[i] != '\n' && liste[i])
		i++;
	if (!liste[i])
	{
		free(liste);
		return (NULL);
	}
	while (liste[j] != '\0')
		j++;
	remains = malloc(sizeof(char) * j);
	if (!remains)
		return (NULL);
	i++;
	j = 0 ;
	while (liste[i])
		remains[j++] = liste[i++];
	remains[j] = '\0';
	free(liste);
	return (remains);
}

char	*ft_get_line(char *liste)
{
	char	*line;
	int		i;

	i = 0;
	if (!liste[i])
		return (NULL);
	while (liste[i] != '\n' && liste[i] != '\0')
		i++;
	line = malloc(sizeof (char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (liste[i] != '\n' && liste[i] != '\0')
	{
		line[i] = liste[i];
		i++;
	}
	if (liste[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *liste )
{
	char	*buf;
	int		nb_read;

	nb_read = 1 ;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE + 1);
	while (buf && !ft_strchr(buf, '\n'))
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buf);
			free(liste);
			return (NULL);
		}
		if (nb_read <= 0)
			break ;
		buf[nb_read] = '\0' ;
		liste = ft_strjoin(liste, buf);
	}
	free(buf);
	return (liste);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	char *line = NULL ;
// 	int fd = 0 ;

// 	fd = open("test", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	printf("%s", get_next_line(fd));
// 	fd = open("test", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return 0;
// }
