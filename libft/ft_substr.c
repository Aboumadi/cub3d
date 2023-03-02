/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:04:12 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/25 20:07:45 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *src, int s, int len)
{
	int	i;
	char			*dst;
	int	j;

	i = 0;
	if (!src)
		return (NULL);
	j = 0;
	while (i < len && src[i++] != '\0')
		j++;
	dst = malloc((j + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len && (s <= ft_strlen(src)) && (src[i + s] != '\0'))
	{
		dst[i] = src[i + s];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
