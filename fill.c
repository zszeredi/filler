/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:04:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/07 11:44:45 by zszeredi         ###   ########.fr       */
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
	x = 0;
	ptr->coo.n = n;
	while (line[x] != '\0')
	{
		if (line[x] == ptr->me)
		{
			bridge(ptr, x, ptr->me);
			if (ptr->counter  == -1)
			{
				ptr->me_s.x = ptr->coo.x;
				ptr->me_s.n = ptr->coo.n;
				ptr->counter = 0;
			}
			if (ptr->counter == 0)
			{
				ptr->up.x = ptr->coo.x;
				ptr->up.n = ptr->coo.n;
				ptr->counter = 1;
			}
			ptr->down.x = ptr->coo.x;
			ptr->down.n = ptr->coo.n;
		}
		else if (line[x] == ptr->opp)
			bridge(ptr, x, ptr->opp);
		x++;
	}
	return (ptr);
}

t_filler		*fill_up(t_filler *ptr)
{
	int		n;
	FILE *fp;
	static int i;
	fp = fopen("text", "a");
	n = 0;
	i = 0;
	while (ft_strstr(ptr->line, "Piece") == NULL)//n < ptr->lines)
	{
		get_next_line(0, &ptr->line);
		fprintf(fp, "%s\n", ptr->line);
		if ((ft_strchr(ptr->line, ptr->me)) != 0 || (ft_strchr(ptr->line, ptr->opp)) != 0)
			read_chara(ptr, ptr->line, n);
		n++;
		i++;
	}
	fprintf(fp, "ptr->up %d %d\n", ptr->up.n, ptr->up.x);
	fprintf(fp, "ptr->down %d %d\n", ptr->down.n, ptr->down.x);
	fclose(fp);
	if (ptr->q == 0)
		ptr->q = quadrant(ptr);
	ptr->counter = 0;
	return (ptr);
}
