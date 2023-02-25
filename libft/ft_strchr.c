/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:20:22 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/24 23:28:51 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*char	*ft_strchr(char *str, int c)
{
	int		i;
	//char	c2;

	//c2 = c;
	i = 0;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
	{
		return ((char *)str);
	}
	return (NULL);
}*/
char	*ft_strchr(char *s, int c)
{
	while (s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	else
	{
		return (NULL);
	}
}
