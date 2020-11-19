/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:33:43 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/07 20:37:39 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



t_tetra 	*ext_coords(t_tetra *tet, int c)
{
	int i;

	i = 0;

	while (i < tet->index)
	{
		if ((tet->cordis[i].x < tet->l.x && c == 0) || (tet->cordis[i].x <= tet->l.x && c == 1))
			tet->l = coord_copy(tet->l, tet->cordis[i].x, tet->cordis[i].n);
		if ((tet->cordis[i].x >= tet->r.x && c == 0) || (tet->cordis[i].x >= tet->l.x && c == 1))
			tet->r = coord_copy(tet->r, tet->cordis[i].x, tet->cordis[i].n);
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

static t_tetra			*save_cordis(t_filler *ptr, t_tetra *tet, int i)
{
	int j;

	while (i <= tet->t_lin)
	{
		j = 0;
		while (j <= tet->t_col)
		{
			if (j == 0 && i == 0)
				ptr->coo = coord_copy(ptr->coo, j, i);
			if (tet->tetra[i][j] == '*')
			{
				tet->cordis[tet->index] = coord_copy(tet->cordis[tet->index], j, i);
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

static t_tetra	*insert_tetra(t_tetra *tet, t_filler *ptr)
{
	int i;

	i = 0;
	tet->index = 0;
	if(!(tet->cordis = malloc(tet->num_stars * sizeof(t_coords))))
		return (NULL);
	cut_off(tet);
	save_cordis(ptr, tet, i);
	tet->l.x = tet->cordis[i].x;
	tet->l.n = tet->cordis[i].n;
	tet->r.x = tet->cordis[i].x;
	tet->r.n = tet->cordis[i].n;
	return(tet);
}


static t_tetra	*get_ttable_size(char *line, t_tetra *tet)
{
	char **sizes;

	sizes = ft_strsplit(line, ' ');
	tet->t_lin = ft_atoi(sizes[1]);
	tet->t_col = ft_atoi(sizes[2]);
	delete_double_array(sizes, 3);
	return (tet);
}


t_filler			*tetro_read(t_filler *ptr, char *line)
{
	int		i;
	t_tetra	*tet;
	i = 0;
	if(!(tet = malloc(sizeof(t_tetra))))
		return (NULL);
	get_ttable_size(line, tet);
	tet->num_stars = 0;
	if(!(tet->tetra = ft_memalloc((tet->t_lin + 1) * sizeof(char*))))
		return (NULL);
	while (i < tet->t_lin)
	{
		free(line);
		get_next_line(0, &line);
		if(!(tet->tetra[i] = ft_strdup(line)))
			return (NULL);
		tet->num_stars += ft_strnchr(line, '*');
		i++;
	}
	insert_tetra(tet, ptr);
	algo(ptr, tet);
	delete_double_array(tet->tetra, tet->t_lin);
	free(tet->cordis);
	free(tet);
	free(line);
	return (ptr);
}