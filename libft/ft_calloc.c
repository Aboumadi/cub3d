/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:08:31 by aboumadi          #+#    #+#             */
/*   Updated: 2021/11/07 15:20:56 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t l, size_t s)
{
	void	*str;

	str = malloc(l * s);
	if (!str)
		return (0);
	ft_bzero(str, (l * s));
	return (str);
}
