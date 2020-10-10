/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:33:43 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/10 13:07:25 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		cut_off_lin(t_tetra *tet, int n, int cal)
{
	int x;
	int counter;
	FILE *fp;

	fp = fopen("tetros", "a");
	x = 0;
	counter = 0;
	while (x <= tet->col)
	{
		if (x == tet->col)
		{
			fprintf(fp, "hello");
			counter++;
			n = 0;
			cal > 0 ? n++ : n--;
		}
		if (tet->tetra[n][x] != '*')
			x++;
		else
			break ;
	}
	fclose(fp);
	return(counter);
}

int		cut_off_col(t_tetra *tet, int x, int cal)
{
	int n;
	int counter;
	FILE *fp;

	fp = fopen("tetros", "a");
	n = 0;
	counter = 0;
	while (n <= tet->lin)
	{
		if (n == tet->lin)
		{
			fprintf(fp, "here");
			counter++;
			n = 0;
			cal > 0 ? x++ : x--;
		}
		if (tet->tetra[n][x] != '*')
			n++;
		else
			break ;
	}
	fclose(fp);
	return(counter);
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
	fprintf(fp, "lin = %d col = %d\n", tet->lin, tet->col);
	if(!(tet->tetra = ft_memalloc((tet->lin + 1) * sizeof(char*))))
		return (NULL);
	while (i < tet->lin)
	{
		get_next_line(0, &line);
		if(!(tet->tetra[i] = ft_strdup(line)))
			return (NULL);
		fprintf(fp, "%s\n", tet->tetra[i]);
		i++;
	}
	tet->del_col_s = cut_off_col(tet, 0, 1);
	tet->del_col_e = cut_off_col(tet, tet->col - 1, 0);
	tet->del_row_s = cut_off_lin(tet, 0, 1);
	tet->del_row_e = cut_off_lin(tet, tet->lin - 1, 0);
	fprintf(fp, "col.s %d col.e %d row.s %d row.e %d", tet->del_col_s, tet->del_col_e, tet->del_row_s, tet->del_row_e);
	fclose(fp);
	return (tet);
}
