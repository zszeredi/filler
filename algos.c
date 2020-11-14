#include "filler.h"
# include <stdio.h>

t_tetra			*push_ud(t_filler *ptr, t_tetra *tet, int i)
{
	FILE *fp;

	ext_coords(ptr, tet, i);
	fp = fopen("text", "w");
	if (ptr->q == 4 || ptr->q == 2)
	{
		fprintf(fp, "GOING up\n");
		tet->push_x = ptr->up.x - tet->r.x;
		tet->push_n = ptr->up.n - tet->r.n;
		if (i == 1)
			fprintf(fp, "changing direction right");
	}
	else if (ptr->q == 1 || ptr->q == 3)
	{
		fprintf(fp, "GOING down\n");
		tet->push_x = ptr->down.x - tet->l.x;
		tet->push_n = ptr->down.n - tet->l.n;
		if (i == 1)
			fprintf(fp, "changing direction left");
	}
	fclose(fp);
	return (tet);
}

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
			ptr->coo.x = x - tet->del_col_s;
			ptr->coo.n = n - tet->del_row_s;
		}
		if (a == ptr->opp_line  || b <= 2)
			ptr->intersection = 1;
		ptr->table[a][b] = ptr->me;
		i++;
	}
	return (ptr);
}

int 		compare(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	FILE *fp;
	int counter;
	fp = fopen("text", "a");
	i = 0;
	counter = 0;
	while (i < tet->index && ptr->table[tet->cordis[i].n + n][tet->cordis[i].x + x] != '\0')
	{
		fprintf(fp, "i = %d\n", i);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n, tet->cordis[i].x);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n + n, tet->cordis[i].x + x);
		//fclose(fp);
		//fp = fopen("insert", "a");
		if (ptr->table[tet->cordis[i].n + n][tet->cordis[i].x + x] == ptr->opp)
		{
			fprintf(fp, "DOES NOT FIT\n");
			fclose(fp);
			return (-1);
		}
		else if (ptr->table[tet->cordis[i].n + n][tet->cordis[i].x + x] != '.')
		{
			fprintf(fp, "counter  = %d\n", counter);
			counter++;
			fprintf(fp, "counter  = %d\n", counter);
		}
		i++;
	}
	fprintf(fp, "counter  = %d\n", counter);
	if (counter == 1)
	{
		fprintf(fp, "OK\n");
		fclose(fp);
		return (1);
	}
	fprintf(fp, "WRONG\n");
	fclose(fp);
	return (-1);
}

t_tetra			*push_it(t_filler *ptr, t_tetra *tet, int i, int j)
{
	ext_coords(ptr, tet, 1);
	if (ptr->q == 4 || ptr->q == 2)
	{
		tet->push_x = j - tet->r.x;
		tet->push_n = i - tet->r.n;
	}
	else if (ptr->q == 1 || ptr->q == 3)
	{
		tet->push_x = j - tet->l.x;
		tet->push_n = i - tet->l.n;
	}
	return (tet);
}

int 			find_place(t_filler *ptr, t_tetra *tet)
{
	int i;
	int j;
	int lim;

	i = ptr->up.n;
	j = ptr->up.x;
	push_ud(ptr, tet, 1);
	while (i < ptr->lines)
	{
		lim = ft_strnchr(ptr->table[i], ptr->me + 32);
		while (j < ptr->columns || j < lim)
		{
			if (compare(ptr, tet, tet->push_x, tet->push_n) == 1)
			{
				place(ptr, tet, tet->push_x, tet->push_n);
				return (1);
			}
		}
		i++;
		j = 0;
	}
	return  (-1);
}


t_tetra 		*push_calc(t_filler *ptr, t_tetra *tet, int index)
{
	tet->push_x = ptr->up.x - tet->cordis[index].x;
	tet->push_n = ptr->up.n - tet->cordis[index].n;
	return (tet);
}

void			algorithm(t_filler *ptr, t_tetra *tet)
{
	int index;
	int num;
	FILE *fp;

	fp = fopen ("calc", "a");
	num = 0;
	index = 0;
	fprintf(fp, "ALGORITHM\n");
	while (index < tet->num_stars) // try to insert in first line through different point in tetro
	{
		fprintf(fp, "MOVIN TETRO\n");
		push_calc(ptr, tet, index);
		num = compare(ptr, tet, tet->push_x, tet->push_n);
		if (num == 1)
			place(ptr, tet, tet->push_x, tet->push_n);
		else
			index++;
		fprintf(fp, "index = %d\n", index);
	}
	if (index == tet->num_stars) //try pushing it, only check left and right
	{
		fprintf(fp, "PUSHING TETRO\n");
		num = find_place(ptr, tet);
		if (num  == -1)
		{
			ptr->coo.x = 0;
			ptr->coo.n = 0;
		}
	}
	fclose(fp);
}

t_filler		*algo(t_filler *ptr, t_tetra *tet)
{
	FILE *fp;
	fp = fopen("text", "a");
	int num;
	fprintf(fp, "up %d %d down %d %d coo %d %d \n", ptr->up.n, ptr->up.x, ptr->down.n, ptr->down.x, ptr->coo.n, ptr->coo.n);
	fprintf(fp, "ptr->opp_line = %d intersect = %d\n", ptr->opp_line, ptr->intersection);
	push_ud(ptr, tet, 0);
	fprintf(fp, "push %d %d\n", tet->push_n, tet->push_x);
	num = compare(ptr, tet, tet->push_x, tet->push_n);
	if (num == 1)
	{
		place(ptr, tet, tet->push_x, tet->push_n);
		fprintf(fp, "inseted\n");
	}
	else
		algorithm(ptr, tet);
	fprintf(fp, "\nintersection = %d\n", ptr->intersection);
	fprintf(fp, "coo %d %d\n", ptr->coo.n, ptr->coo.x);
	fclose(fp);
	return (ptr);
}