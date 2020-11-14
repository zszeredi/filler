/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:59:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/07 20:37:40 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*t_filler		*place(t_filler *ptr, t_tetra *tet, int x, int n)
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
			ptr->coo.x = x - tet->del_col_s;
			ptr->coo.n = n - tet->del_row_s;
		}
		if (a == ptr->opp_line  || b <= 2)
		{
			ptr->me_s.n = a;
			ptr->me_s.x = b;
			ptr->intersection = 1;
		}
		ptr->table[a][b] = ptr->me + 32;
		i++;
	}
	return (ptr);
}

int 		compare(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	FILE *fp;
	static int counter;
	fp = fopen("text", "a");
	i = 0;
	while (i < tet->index && ptr->table[tet->cordis[i].n][tet->cordis[i].x] != '\0')
	{
		fprintf(fp, "i = %d\n", i);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n, tet->cordis[i].x);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n + n, tet->cordis[i].x + x);
		if (ptr->table[tet->cordis[i].n + n][tet->cordis[i].x + x] == ptr->me + 32)
		{
			fprintf(fp, "counter  = %d\n", counter);
			counter++;
		}
		if (ptr->table[tet->cordis[i].n + n][tet->cordis[i].x + x] == ptr->opp + 32|| counter > 1)
		{
			fprintf(fp, "DOES NOT FIT\n");
			return (-1);
		}
		i++;
	}
	fprintf(fp, "counter  = %d\n", counter);
	//if (counter < 1)
	//	return (-1);
	counter = 0;
	fprintf(fp, "ok\n");
	fclose(fp);
	return (1);
}*/
