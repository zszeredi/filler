/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:33:43 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/11 12:36:33 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_tetra 	*ext_coords(t_tetra *tet)
{
	int i;

	i = 0;
	tet->l.x = tet->cordis[i].x;
	tet->l.n = tet->cordis[i].n;
	tet->r.x = tet->cordis[i].x;
	tet->r.n = tet->cordis[i].n;
	while (i < tet->index)
	{
		if (tet->cordis[i].x < tet->l.x)
		{
			tet->l.x = tet->cordis[i].x;
			tet->l.n = tet->cordis[i].n;
		}
		if (tet->cordis[i].x > tet->r.x)
		{
			tet->r.x = tet->cordis[i].x;
			tet->r.n = tet->cordis[i].n;
		}
		i++;
	}
	return (tet);
}

static t_tetra 	*quadrant(t_tetra *tet, t_table *t)
{
	int ud;
	int lr;
	if (t->me_s.x < tet->col / 2)
		lr = 1;
	else
		lr = 2;
	if (t->me_s.n < tet->lin / 2)
		ud = 1;
	else
		ud = 2;
	if (lr == 1 && ud == 1)
		tet->q = 1;
	if (lr == 2 && ud == 1)
		tet->q = 2;
	if (lr == 1 && ud == 2)
		tet->q = 3;
	if (lr == 2 && ud == 2)
		tet->q = 4;
	return (tet);
}

t_table			*place(t_tetra *tet, t_table *t, t_filler *ptr)
{
	quadrant(tet, t);
	ext_coords(tet);
	//algo where to put it;
	//overlap with my chara coordinate
	//check if I am not out of the table
	//insert
	return (t);
}

t_tetra			*deduct(t_tetra *tet)
{
	int i;
	FILE *fp;

	fp = fopen("coords", "w");
	fprintf(fp, "index = %d", tet->index);
	i = 0;
	if (tet->del_col_s > 0)
	{
		while (i < tet->index)
		{
			fprintf(fp, "col_Del\n");
			fprintf(fp, "tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n);
			tet->cordis[i].x -= tet->del_col_s;
			fprintf(fp, "tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n);
			i++;
		}
	}
	if (tet->del_row_s > 0)
	{
		i = 0;
		while (i < tet->index)
		{
			fprintf(fp, "row_Del\n");
			fprintf(fp, "tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n);
			tet->cordis[i].n -= tet->del_row_s;
			fprintf(fp, "tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n);
			i++;
		}
	}
	fclose(fp);
	return (tet);
}

t_tetra			*save_cordis(t_tetra *tet, int i, int j)
{
	FILE *fp;
	fp = fopen("doc", "w");
	while (i <= tet->lin)
	{
		j = 0;
		while (j <= tet->col)
		{
			if (tet->tetra[i][j] == '*')
			{
				tet->cordis[tet->index].x = j;
				tet->cordis[tet->index].n = i;
				fprintf(fp, "tet->cordis[%d].%d.%d\n", tet->index, tet->cordis[tet->index].x, tet->cordis[tet->index].n);
				tet->index++;
			}
			if (tet->index == tet->num_stars)
			{
				if (tet->del_col_s > 0 || tet->del_row_s > 0)
					deduct(tet);
				fclose(fp);
				return (tet);
			}
			j++;
		}
		i++;
	}
	fclose(fp);
	return (tet);
}

t_tetra			*insert_tetra(t_tetra *tet, t_table *t, t_filler *ptr)
{
	int i;
	int j;

	i = 0;
	tet->index = 0;
	if(!(tet->cordis = malloc(tet->num_stars * sizeof(t_coords))))
		return (NULL);
	cut_off(tet);
	save_cordis(tet, i, j);
	place(tet, t, ptr);
	return(tet);
}

t_tetra			*tetro_read(t_filler *ptr, t_table *t, t_tetra *tet)
{
	int		i;
	char	*line;
	char 	**tab;
	FILE 	*fp;
	i = 0;
	fp = fopen("tetros", "w");
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	tet->lin = ft_atoi(tab[1]);
	tet->col = ft_atoi(tab[2]);
	tet->num_stars = 0;
	fprintf(fp, "lin = %d col = %d\n", tet->lin, tet->col);
	if(!(tet->tetra = ft_memalloc((tet->lin + 1) * sizeof(char*))))
		return (NULL);
	while (i < tet->lin)
	{
		get_next_line(0, &line);
		if(!(tet->tetra[i] = ft_strdup(line)))
			return (NULL);
		tet->num_stars += ft_strnchr(line, '*');
		fprintf(fp, "%s\n", tet->tetra[i]);
		i++;
	}
	insert_tetra(tet, t, ptr);
	fprintf(fp, "col.s %d col.e %d row.s %d row.e %d num_stars = %d\n", tet->del_col_s, tet->del_col_e, tet->del_row_s, tet->del_row_e, tet->num_stars);
	fclose(fp);
	return (tet);
}