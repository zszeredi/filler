/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:04:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/10 11:04:55 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_table			*insert(t_table *t, char c, t_coords coord)
{
	if (t->table[coord.n][coord.x] != '\0' && t->table[coord.n][coord.x] == '.')
		t->table[coord.n][coord.x] = c;
	return (t);
}

static t_table			*bridge(t_table *t, int x, char c)
{
	t->coo.x = x - 4;
	insert(t, c, t->coo);
	return (t);
}

static t_table			*read_chara(t_filler *ptr, t_table *t, char *line, int n)
{
	int			x;
	static int	counter;

	counter = 0;
	x = 0;
	t->coo.n = n - 1;
	while (line[x] != '\0')
	{
		if (line[x] == ptr->me)
		{
			bridge(t, x, ptr->me);
			if (counter == 0)
			{
				t->me_s.x = t->coo.x;
				t->me_s.n = t->coo.n;
				counter = 1;
			}
		}
		else if (line[x] == ptr->opp)
			bridge(t, x, ptr->opp);
		x++;
	}
	return (t);
}

t_table			*fill_up(t_filler *ptr, t_table *t)
{
	int		n;
	FILE	*fp;
	char	*line;

	n = 0;
	fp = fopen("table", "w");
	while (n <= ptr->lines)
	{
		get_next_line(0, &line);
		if ((ft_strchr(line, ptr->me)) != 0 || (ft_strchr(line, ptr->opp)) != 0)
			read_chara(ptr, t, line, n);
		fprintf(fp, "%s\n", line);
		n++;
	}
	fclose(fp);
	return (t);
}
