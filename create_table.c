/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:17:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/31 16:10:19 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			dot(char *s, int i)
{
	while (i > 0)
	{
		i--;
		s[i] = '.';
	}
}

static t_filler		*get_table_size(char *line, t_filler *ptr)
{
	char	**sizes;

	sizes = ft_strsplit(line, ' ');
	ptr->lines = ft_atoi(sizes[1]);
	ptr->columns = ft_atoi(sizes[2]);
	ft_delete_double_array(sizes, 3);
	return (ptr);
}

t_filler			*create_table(t_filler *ptr, char *line)
{
	int	i;

	i = -1;
	get_table_size(line, ptr);
	if (!(ptr->table = ft_memalloc((ptr->lines) * sizeof(char*))))
	{
		ft_delete_double_array(ptr->table, ptr->lines);
		return (NULL);
	}
	while (++i < ptr->lines)
	{
		if (!(ptr->table[i] = ft_memalloc((ptr->columns + 1) * sizeof(char))))
		{
			ft_delete_double_array(ptr->table, ptr->lines);
			return (NULL);
		}
		else
		{
			dot(ptr->table[i], ptr->columns);
			dot(*ptr->table, ptr->lines);
		}
	}
	return (ptr);
}
