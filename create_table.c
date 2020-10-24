/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:17:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/24 14:53:49 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler			*delete_table(char **str, t_filler *ptr)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
	return (ptr);
}

static t_filler 	*quadrant(t_filler *ptr)
{
	int ud;
	int lr;
	if (ptr->me_s.x < ptr->columns / 2)
		lr = 1;
	else
		lr = 2;
	if (ptr->me_s.n < ptr->lines / 2)
		ud = 1;
	else
		ud = 2;
	if (lr == 1 && ud == 1)
		ptr->q = 1;
	if (lr == 2 && ud == 1)
		ptr->q = 2;
	if (lr == 1 && ud == 2)
		ptr->q = 3;
	if (lr == 2 && ud == 2)
		ptr->q = 4;
	return (ptr);
}

static void		dot(char *s, int i)
{
	while (i > 0)
	{
		i--;
		s[i] = '.';
	}
}

static t_filler	*get_table_size(char *line, t_filler *ptr)
{
	char **sizes;

	sizes = ft_strsplit(line, ' ');
	ptr->lines = ft_atoi(sizes[1]);
	ptr->columns = ft_atoi(sizes[2]);
	ft_strdel(sizes);
	return (ptr);
}

t_filler	*create_table(t_filler *ptr, char *line)
{
	int	i;

	i = -1;
	get_table_size(line, ptr);
//	get_table_size(line, ptr->lines, ptr->columns);
	if (!(ptr->table = ft_memalloc((ptr->lines + 1) * sizeof(char*))))
		return (delete_table(ptr->table, ptr));
	while (++i < ptr->lines)
	{
		if (!(ptr->table[i] = ft_memalloc((ptr->columns + 1) * sizeof(char))))
			return (delete_table(ptr->table, ptr));
		else
		{
			dot(ptr->table[i], ptr->columns);
			dot(*ptr->table, ptr->lines);
		}
	}
	quadrant(ptr);
	fill_up(ptr, line);
	return (ptr);
}
