/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:40:02 by mnajid            #+#    #+#             */
/*   Updated: 2022/10/22 15:35:29 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	ptr = malloc(a + b + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1, a + 1);
	ft_strlcat(ptr, (char *)s2, a + b + 1);
	return (ptr);
}
