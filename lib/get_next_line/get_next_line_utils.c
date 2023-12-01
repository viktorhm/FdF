/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:22:52 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/14 10:32:28 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t count)
{
	unsigned char	*string;
	size_t			i;

	if (count == 0)
		return ;
	i = 0;
	string = str;
	while (i < count)
	{
		string[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_finale;
	int		nb;

	nb = ft_strlen(s1) + ft_strlen(s2);
	str_finale = malloc(nb + 1);
	if (!str_finale)
		return (NULL);
	ft_bzero(str_finale, nb + 1);
	ft_strlcat(str_finale, s1, nb + 1);
	ft_strlcat(str_finale, s2, nb + 1);
	free(s1);
	return (str_finale);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res_d;
	unsigned int	res_s;

	i = ft_strlen(dest);
	j = 0;
	res_d = ft_strlen(dest);
	res_s = ft_strlen(src);
	if (size < 1)
		return (res_s + size);
	if (src == NULL)
		return (0);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < res_d)
		return (res_s + size);
	else
		return (res_d + res_s);
}
