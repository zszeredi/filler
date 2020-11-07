/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:59:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/07 19:03:47 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler		*place(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	int a;
	int b;
	i = 0;
	while(i < tet->index)
	{
		b = tet->cordis[i].x + x;
		a = tet->cordis[i].n + n;
		if (i == 0)
		{
			ptr->sb.x = x - tet->del_col_s;
			ptr->sb.n = n - tet->del_row_s;
		}
		ptr->table[a][b] = ptr->me + 32;
		i++;
	}
	return (ptr);
}

t_filler	*intersection(t_filler *ptr, t_coords coord, int a, int x)
{

	if (a == ptr->opp_line - 1 || a == ptr->opp_line + 1  || coord.x + x  <= 2) // protection if I am close too the wall
	{
		ptr->strat = 1;
		ptr->me_s.n = a;
		ptr->me_s.x = coord.x + x;
	}
	return (ptr);
}

int 		compare(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	int counter;
	FILE *fp;
	FILE *fp2;
	fp = fopen("text", "a");
	fp2 = fopen("err", "a");
	i = 0;
	counter = 0;
	while (i < tet->index && ptr->table[tet->cordis[i].n][tet->cordis[i].x] != '\0')
	{
		fprintf(fp, "counter = %d\n", counter);
		if (ptr->table[tet->cordis[i].n + n][tet->cordis[i].x + x] == ptr->me)
			++counter;
		fprintf(fp, "i = %d\n", i);
		fprintf(fp, "counter = %d\n", counter);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n, tet->cordis[i].x);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n + n, tet->cordis[i].x + x);
		if (ptr->table[tet->cordis[i].n + n][tet->cordis[i].x + x] == ptr->opp || counter > 1)
		{
			if (counter > 1)
				fprintf(fp2, "overlap\n");
			else
				fprintf(fp2, "no fit\n");
			fclose(fp2);
			return(-1);
		}

		if (ptr->strat == 0 || ptr->strat == 12)
			intersection(ptr, tet->cordis[i], tet->cordis[i].n + n, x); // might have to +- 1 as I might not have place

		i++;
	}
	fprintf(fp, "ok");
	fclose(fp);
	return (1);
}
