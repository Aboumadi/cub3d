/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:01:47 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/13 14:43:04 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;
	t_list	*tmp;

	tmp = *lst;
	if (del)
	{
		while (tmp)
		{
			nxt = tmp->next;
			del(tmp->content);
			free(tmp);
			tmp = nxt;
		}
		*lst = NULL;
	}
}
