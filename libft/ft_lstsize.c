/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:49:36 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/13 15:07:45 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		cp;

	tmp = lst;
	cp = 0;
	while (tmp)
	{
		tmp = tmp->next;
		cp++;
	}
	return (cp);
}
