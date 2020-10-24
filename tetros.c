/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:33:43 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/24 14:54:22 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_tetra			*delete_tetra(char **str, t_tetra *tet)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
	return (tet);
}


t_coords		coord_copy(t_coords coo, int i, int j)
{
	coo.x = i;
	coo.n = j;
	return (coo);
}

static t_tetra 	*ext_coords(t_filler *ptr, t_tetra *tet)
{
	int i;

	i = 0;
	tet->l.x = tet->cordis[i].x;
	tet->l.n = tet->cordis[i].n;
	tet->r.x = tet->cordis[i].x;
	tet->r.n = tet->cordis[i].n;
	while (i < tet->index)
	{
		if ((tet->cordis[i].x < tet->l.x && ptr->q == 1) || (tet->cordis[i].x <= tet->l.x && ptr->q == 3))
		{
			tet->l.x = tet->cordis[i].x;
			tet->l.n = tet->cordis[i].n;
		}
		if ((tet->cordis[i].x > tet->r.x && ptr->q == 2) || (tet->cordis[i].x >= tet->r.x && ptr->q == 4))
		{
			tet->r.x = tet->cordis[i].x;
			tet->r.n = tet->cordis[i].n;
		}
		i++;
	}
	return (tet);
}

static t_tetra			*deduct(t_tetra *tet)
{
	int i;

	i = 0;
	if (tet->del_col_s > 0)
	{
		while (i < tet->index)
		{
			tet->cordis[i].x -= tet->del_col_s;
			i++;
		}
	}
	if (tet->del_row_s > 0)
	{
		i = 0;
		while (i < tet->index)
		{
			tet->cordis[i].n -= tet->del_row_s;
			i++;
		}
	}
	return (tet);
}

static t_tetra			*save_cordis(t_tetra *tet, int i)
{
	int j;

	while (i <= tet->t_lin)
	{
		j = 0;
		while (j <= tet->t_col)
		{
			if (tet->tetra[i][j] == '*')
			{
				tet->cordis[tet->index].x = j;
				tet->cordis[tet->index].n = i;
				tet->index++;
			}
			if (tet->index == tet->num_stars)
			{
				if (tet->del_col_s > 0 || tet->del_row_s > 0)
					deduct(tet);
				return (tet);
			}
			j++;
		}
		i++;
	}
	return (tet);
}

static t_tetra			*insert_tetra(t_tetra *tet, t_filler *ptr)
{
	int i;

	i = 0;
	tet->index = 0;
	if(!(tet->cordis = malloc(tet->num_stars * sizeof(t_coords))))
		return (NULL);
	cut_off(tet);
	save_cordis(tet, i);
	printf("%d %d", tet->cordis[0].x, tet->cordis[0].n);
	ext_coords(ptr, tet);
	algo(ptr, tet);
	return(tet);
}

t_filler			*tetro_read(t_filler *ptr, char *line)
{
	int		i;
	char 	**tab;
	t_tetra	*tet;
	FILE 	*fp; // out
	i = 0;
	if(!(tet = malloc(sizeof(t_tetra))))
		return (NULL);
	fp = fopen("tetros", "w"); //o
//	get_table_size(line, tet->t_lin, tet->t_col);
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	tet->t_lin = ft_atoi(tab[1]);
	tet->t_col = ft_atoi(tab[2]);
	tet->num_stars = 0;
	fprintf(fp, "lin = %d col = %d\n", tet->t_lin, tet->t_col); //oo
	if(!(tet->tetra = ft_memalloc((tet->t_lin + 1) * sizeof(char*))))
		return (NULL);
	while (i < tet->t_lin)
	{
		get_next_line(0, &line);
		if(!(tet->tetra[i] = ft_strdup(line)))
			return (NULL);
		tet->num_stars += ft_strnchr(line, '*');
		fprintf(fp, "%s\n", tet->tetra[i]); //oo
		ft_strdel(&line);
		i++;
	}
	fclose(fp); // oo
	insert_tetra(tet, ptr);
	delete_tetra(tet->tetra, tet);
	free(tet);
	return (ptr);
}
