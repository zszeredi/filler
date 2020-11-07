/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:04:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/07 09:51:57 by zszeredi         ###   ########.fr       */
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
	FILE *fp;
	fp = fopen("line", "a");
	x = 0;
	ptr->coo.n = n;
	while (line[x] != '\0')
	{
		if (line[x] == ptr->me)
		{
			bridge(ptr, x, ptr->me);
			if (ptr->counter == 0 && ptr->q == 4)
			{
				fprintf(fp, "first %d\n", n);
				ptr->me_s.x = ptr->coo.x;
				ptr->me_s.n = n;
				ptr->counter = 1;
			}
			else if (ptr->counter == 0)
			{
				fprintf(fp, "last  %d\n", n);
				ptr->me_s.x = ptr->coo.x;
				ptr->me_s.n = n;
			}
		}
		else if (line[x] == ptr->opp)
			bridge(ptr, x, ptr->opp);
		x++;
	}
	fclose(fp);	
	return (ptr);
}

t_filler		*fill_up(t_filler *ptr, int counter)
{
	int		n;
	FILE *fp;
	FILE *fp2;

	fp = fopen("text", "a");
	fp2 = fopen("line", "a");
	n = 0;
	fprintf(fp2, "helo\n");
	fclose(fp2);
	while (ft_strstr(ptr->line, "Piece") == NULL)//n < ptr->lines)
	{
		get_next_line(0, &ptr->line);
		fprintf(fp, "%s\n", ptr->line);
		if ((ft_strchr(ptr->line, ptr->me)) != 0 || (ft_strchr(ptr->line, ptr->opp)) != 0)
			read_chara(ptr, ptr->line, n);
		//		if (ft_strstr(ptr->line, "Piece") == NULL)
		//			ft_strdel(&ptr->line);
//		if (n == 0)
//			i = 1;
		n++;
		
	}
	fprintf(fp, "ptr->me_s %d %d\n", ptr->me_s.n, ptr->me_s.x);
	fclose(fp);
	fp2 = fopen("line", "a");
	fprintf(fp2, "bye\n");
	fclose(fp2);
	if (ptr->q == 0)
		ptr->q = quadrant(ptr);
	ptr->counter = 0;
	return (ptr);
}
