/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:04:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/24 19:21:15 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler		*insert(t_filler *ptr, char c, t_coords coord)
{
	if (ptr->table[coord.n][coord.x] != '\0' && ptr->table[coord.n][coord.x] == '.')
		ptr->table[coord.n][coord.x] = c;
	return (ptr);
}

static t_filler			*bridge(t_filler *ptr, int x, char c)
{
	ptr->coo.x = x - 4;
	insert(ptr, c, ptr->coo);
	return (ptr);
}

static t_filler			*read_chara(t_filler *ptr, char *line, int n)
{
	int			x;
	static int	counter;

	counter = 0;
	x = 0;
	ptr->coo.n = n;
	while (line[x] != '\0')
	{
		if (line[x] == ptr->me)
		{
			bridge(ptr, x, ptr->me);
			if (counter == 0)
			{
				ptr->me_s.x = ptr->coo.x;
				ptr->me_s.n = ptr->coo.n;
				counter = 1;
			}
		}
		else if (line[x] == ptr->opp)
			bridge(ptr, x, ptr->opp);
		x++;
	}
	return (ptr);
}

t_filler		*fill_up(t_filler *ptr, char *line)
{
	int		n;
	FILE	*fp;

	n = 0;
	fp = fopen("table", "w");
	if ((ft_strchr(line, ptr->me)) != 0 || (ft_strchr(line, ptr->opp)) != 0)
			read_chara(ptr, line, n);
		fprintf(fp, "%s\n", line);
	while (n <= ptr->lines)
	{
		get_next_line(0, &line);
		if ((ft_strchr(line, ptr->me)) != 0 || (ft_strchr(line, ptr->opp)) != 0)
			read_chara(ptr, line, n);
		fprintf(fp, "%s\n", line);
		ft_strdel(&line);
		n++;
	}
	fclose(fp);
	return (ptr);
}
