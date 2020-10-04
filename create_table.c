/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:17:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/04 17:23:08 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			save_cordis(t_coords one, t_coords two,
		t_coords o_pos, t_coords x_pos)
{
	one.x = o_pos.x;
	one.n = o_pos.n;
	two.x = x_pos.x;
	two.n = x_pos.n;
}

static void			dot(char *s, int i)
{
	while (i > 0)
	{
		i--;
		s[i] = '.';
	}
}

static t_table		*delete_table(char **str, t_table *t)
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

static t_table		*get_sp(t_filler *ptr, t_table *t, char *line)
{
	int			lin;
	int			col;
	t_coords	o_pos;
	t_coords	x_pos;
	int			i;

	i = -1;
	lin = 0;
	while (++i < ptr->lines)
	{
		get_next_line(0, &line);
		if ((col = ft_strnchr(line, 'X')) > 0)
		{
			x_pos.x = col;
			x_pos.n = lin;
		}
		else if ((col = ft_strnchr(line, 'O')) > 0)
		{
			o_pos.x = col;
			o_pos.n = lin;
		}
		else
			lin++;
	}
	if (ptr->me == 'O')
		save_cordis(t->me_s, t->opp_s, o_pos, x_pos);
	else
		save_cordis(t->opp_s, t->me_s, o_pos, x_pos);
	return (t);
}

t_table				*create_table(t_filler *ptr, t_table *t)
{
	int		i;
	char	*line;

	line = NULL;
	i = -1;
	if (!(t->table = ft_memalloc((ptr->columns + 1) * sizeof(char))))
		return (delete_table(t->table, t));
	while (++i < ptr->lines)
	{
		if (!(t->table[i] = ft_memalloc((ptr->lines + 1) * sizeof(char))))
			return (delete_table(t->table, t));
		else
		{
			dot(t->table[i], ptr->lines);
			dot(*t->table, ptr->columns);
		}
	}
	t = get_sp(ptr, t, line);
	return (t);
}
