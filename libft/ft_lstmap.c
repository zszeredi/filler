/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:52:35 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 11:31:27 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *newlist;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp = f(lst);
	newlist = tmp;
	while (f && lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			if (!(tmp->next = f(lst)))
			{
				free(tmp->next);
				return (NULL);
			}
			tmp = tmp->next;
		}
		return (newlist);
	}
	return (NULL);
}
