/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:56:06 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/27 00:18:57 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str2)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 1;
	n = 0;
	while (str2[i] == 32 || (str2[i] >= 9 && str2[i] <= 13))
		i++;
	if (str2[i] == '+' || str2[i] == '-')
	{
		if (str2[i] == '-')
			j = j * -1;
		i++;
	}
	while (str2[i] >= '0' && str2[i] <= '9')
	{
		n = (n * 10) + (str2[i] - 48);
		i++;
	}
	return (n * j);
}
