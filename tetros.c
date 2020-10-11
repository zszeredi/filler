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

int		cut_off_lin(t_tetra *tet, int n, int cal)
{
	int x;
	int counter;

	x = 0;
	counter = 0;
	while (x < tet->col &&  n < tet->lin && n >= 0)
	{
		if (tet->tetra[n][x] == '*')
		{
			tet->cordis[tet->index].x = x;
			tet->cordis[tet->index++].n = n;
			return (counter);
		}
		if (x == tet->col - 1)
		{
			counter++;
			x = 0;
			cal > 0 ? n++ : n--;
		}
		else
			x++;
	}
	return(counter);
}

int		cut_off_col(t_tetra *tet, int x, int cal)
{
	int n;
	int counter;

	n = 0;
	counter = 0;
	while (n < tet->lin && x < tet->col && x >= 0)
	{
		if (tet->tetra[n][x] == '*')
		{
			tet->cordis[tet->index].x = x;
			tet->cordis[tet->index++].n = n;
			return (counter);
		}
		if (n == tet->lin - 1)
		{
			counter++;
			n = 0;
			cal == 1 ? x++ : x--;
		}	
		else
			n++;
	}
	return(counter);
}

t_tetra	*set_to_null(t_tetra *tet)
{
	tet->del_col_s = 0;
	tet->del_col_e = 0;
	tet->del_row_s = 0;
	tet->del_row_e = 0;
	return(tet);
}

t_tetra	*deduct(t_tetra *tet)
{
	int i;
	FILE *fp;

	fp = fopen("coords", "w");
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
	i = 0;
	if (tet->del_row_s > 0)
	{
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

t_tetra		*save_cordis(t_tetra *tet)
{
	int i;
	int j;
	i = 0;
	tet->index = 0;
	if(!(tet->cordis = malloc(tet->num_stars * sizeof(t_coords))))
		return (NULL);
	set_to_null(tet);
	tet->del_col_s = cut_off_col(tet, 0, 1);
	tet->del_col_e = cut_off_col(tet, tet->col - 1, 0);
	tet->del_row_s = cut_off_lin(tet, 0, 1);
	tet->del_row_e = cut_off_lin(tet, tet->lin - 1, 0);
	while (i < tet->lin)
	{
		while (j < tet->col)
		{
			j = 0;
			if (tet->tetra[i][j] == '*')
			{
				tet->cordis[tet->index].x = j;
				tet->cordis[tet->index].n = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (tet->del_col_s > 0 || tet->del_row_s > 0)
		deduct(tet);
	return (tet);
}


t_tetra		*tetro_read(t_filler *ptr, t_table *t, t_tetra *tet)
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
	save_cordis(tet);
	fprintf(fp, "col.s %d col.e %d row.s %d row.e %d num_stars = %d", tet->del_col_s, tet->del_col_e, tet->del_row_s, tet->del_row_e, tet->num_stars);
	fclose(fp);
	return (tet);
}
