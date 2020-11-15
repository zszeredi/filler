#include "filler.h"
#include <stdio.h>

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
		if (a == ptr->opp_line || b <= 2)
			ptr->intersection = 1;
		ptr->table[a][b] = ptr->me;
		i++;
	}
	return (ptr);
}

int 		compare(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	int a;
	int b;
	FILE *fp;
	int counter;
	fp = fopen("text", "a");
	i = 0;
	counter = 0;
	while (i < tet->index)
	{
		fprintf(fp, "i = %d\n", i);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n, tet->cordis[i].x);
		fprintf(fp, "ptr->table[%d][%d]\n", tet->cordis[i].n + n, tet->cordis[i].x + x);
		b = tet->cordis[i].x + x;
		a = tet->cordis[i].n + n;
		if (a < 0 || b < 0 || b > ptr->columns - 2 || a > ptr->lines - 1)
		{
			fprintf(fp, "COORD WRONG\n");
			fclose(fp);
			return (-1);
		}
		if ((ptr->table[a][b] == ptr->opp) || counter > 1)
		{
			fprintf(fp, "DOES NOT FIT\n");
			fclose(fp);
			return (-1);
		}
		else if (ptr->table[a][b] != '.')
			counter++;
		i++;
	}
	if (counter > 1 || counter < 1)
	{
		fprintf(fp, "OVERLAPS\n");
		fclose(fp);
		return (-1);
	}
	fprintf(fp, "OK\n");
	fclose(fp);
	return (1);
}

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

	}
	else if (ptr->q == 1 || ptr->q == 3)
	{
		fprintf(fp, "GOING down\n");
		tet->push_x = ptr->down.x - tet->l.x;
		tet->push_n = ptr->down.n - tet->l.n;

	}
	fclose(fp);
	return (tet);
}

t_tetra 		*push_calc(t_tetra *tet, int index, int i, int j)
{
	tet->push_x = j - tet->cordis[index].x;
	tet->push_n = i - tet->cordis[index].n;
	return (tet);
}

int 			find_place(t_filler *ptr, t_tetra *tet)
{
	int i;
	int j;
	int index;

	FILE *fp;
	fp = fopen ("text", "a");
	fprintf (fp, "FIND PLACE\n");
	i = ptr->up.n;
	j = ptr->up.x;
	while (i < ptr->lines)
	{
		while (j < ptr->columns)
		{
			if (ptr->table[i][j] == ptr->me)
			{
				index = 0;
				while (index < tet->num_stars)
				{
					fprintf(fp, "index = %d\n", index);
					fprintf(fp, "table %d %d\n", i, j);
					push_calc(tet, index, i, j);
					if (compare(ptr, tet, tet->push_x, tet->push_n) == 1)
					{
						fp = fopen("text", "a");
						fprintf(fp, "FITS\n");
						place(ptr, tet, tet->push_x, tet->push_n);
						fclose(fp);
						return (1);
					}
					index++;
					fp = fopen("text", "a");
					fprintf(fp, "going forward\n");
				}
			}
			fprintf(fp, "not me\n");
			j++;
		}
		i++;
		j = 0;
	}
	ptr->coo.x = 0;
	ptr->coo.n = 0;
	fprintf(fp, "THE END\n");
	fclose(fp);
	return  (-1);
}

t_filler		*algo(t_filler *ptr, t_tetra *tet)
{
	FILE *fp;
	fp = fopen("text", "a");
	fprintf(fp, "up %d %d down %d %d coo %d %d \n", ptr->up.n, ptr->up.x, ptr->down.n, ptr->down.x, ptr->coo.n, ptr->coo.n);
	fprintf(fp, "ptr->opp_line = %d intersect = %d\n", ptr->opp_line, ptr->intersection);
	push_ud(ptr, tet, 0);
	fprintf(fp, "push %d %d\n", tet->push_n, tet->push_x);
	fclose(fp);
	if (compare(ptr, tet, tet->push_x, tet->push_n) < 1)
	{
		fp = fopen("text", "a");
		fprintf(fp, "algorith");
		find_place(ptr, tet);
	}
	else
		place(ptr, tet, tet->push_x, tet->push_n);
	fp = fopen("text", "a");
	fprintf(fp, "\nintersection = %d\n", ptr->intersection);
	fprintf(fp, "coo %d %d\n", ptr->coo.n, ptr->coo.x);
	fclose(fp);
	return (ptr);
}