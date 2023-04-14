/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:57:58 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/27 03:13:04 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	size_t	x;

	i = 0;
	str = (char *)s;
	while (i <= n)
	{
		if (s[i] == c)
		{
			x = i;
			return (x);
		}
		else
			i++;
	}
	if (x == 0)
		return (s + i);
	return (0);
}
