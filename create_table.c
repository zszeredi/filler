/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:17:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/10 11:33:25 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_table			*delete_table(char **str, t_table *t)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
	return (t);
}

static void		dot(char *s, int i)
{
	while (i > 0)
	{
		i--;
		s[i] = '.';
	}
}

t_table			*create_table(t_filler *ptr, t_table *t)
{
	int	i;

	i = -1;
	if (!(t->table = ft_memalloc((ptr->lines + 1) * sizeof(char*))))
		return (delete_table(t->table, t));
	while (++i < ptr->lines)
	{
		if (!(t->table[i] = ft_memalloc((ptr->columns + 1) * sizeof(char))))
			return (delete_table(t->table, t));
		else
		{
			dot(t->table[i], ptr->columns);
			dot(*t->table, ptr->lines);
		}
	}
	t = fill_up(ptr, t);
	return (t);
}
