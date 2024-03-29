/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:56:24 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/26 17:57:17 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t l)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < l)
	{
		str[i] = '\0';
		i++;
	}
	return ((void)str);
}
