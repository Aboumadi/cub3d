/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:56 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/27 02:57:36 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *str, char *buff)
{
	int		i;
	int		j;
	char	*s3;

	if (!str)
	{
		str = (char *) malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	s3 = malloc((ft_strlen(str) + ft_strlen(buff) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	j = ft_strlen(str);
	i = 0;
	while (str[i] != '\0')
	{
		s3[i] = str[i];
		i++;
	}
	i = 0;
	while (buff[i] != '\0')
		s3[j++] = buff[i++];
	s3[j] = '\0';
	free(str);
	return ((char *)s3);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	c2;

	c2 = c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != c2 && str[i] != '\0')
		i++;
	if (str[i] == c2)
		return ((char *)str + i);
	return (0);
}
