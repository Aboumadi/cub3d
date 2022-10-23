/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:36:44 by mnajid            #+#    #+#             */
/*   Updated: 2022/10/22 15:41:04 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	b;

	if (s1 == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	b = ft_strlen(s1);
	while (b && ft_strchr(set, s1[b]))
		b--;
	return (ft_substr(s1, 0, b + 1));
}