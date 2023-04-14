/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:49:27 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/20 02:21:07 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	j;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	j = 0;
	if (size < dest_size)
		return (size + src_size);
	size -= dest_size;
	if (size != 0)
	{
		while (src[j] != '\0' && size - 1 != 0)
		{
			dest[dest_size + j] = src[j];
			j++;
			size--;
		}
		dest[dest_size + j] = '\0';
	}
	return (dest_size + src_size);
}
