#include "filler.h"

t_filler		*place(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	int m;
	int j;
	int a;
	int b;
	FILE *fp;
	m = 0;
	i = 0;
	fp = fopen("newtable", "w");
	while(i < tet->index)
	{
		b = tet->cordis[i].x + x;
		a = tet->cordis[i].n + n;
		if (i == 0)
		{
			ptr->me_s.x = b;
			ptr->me_s.n = a;
		}
		fprintf(fp, "%d %d\n", b, a);
		ptr->table[a][b] = ptr->me + 32;
		i++;
	}
	while (m < ptr->lines) //loop out
	{
		j = 0;
		while (j <= ptr->columns)
		{
			fprintf(fp, "%c", ptr->table[m][j]);
			j++;
		}
		fprintf(fp, "%d\n", m);
		m++;
	}
	fprintf(fp, "\nme_s.%d.%d\n", ptr->me_s.x, ptr->me_s.n);
	fclose(fp);
	return (ptr);
}

int 		compare(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;

	i = 0;
	while (i < tet->index)
	{
		if (ptr->table[tet->cordis[i].x + x][tet->cordis[i].n + n] == '.')
			i++;
		else
			return (-1);
	}
	return (1);
}

static t_filler		*q_right(t_filler *ptr, t_tetra *tet)
{
	int push_x;
	int push_n;
	FILE *fp;
	int i = 0;
	fp = fopen("right", "w");
	fprintf(fp, "\nme_s.%d.%d\n", ptr->me_s.x, ptr->me_s.n);
	fprintf(fp, "\ntet->r.%d.%d\n", tet->r.x, tet->r.n);
	fprintf(fp, "q = %d", ptr->q);
	push_x = ptr->me_s.x - tet->r.x; // most right
	push_n = ptr->me_s.n - tet->r.n;
	fprintf(fp, "push_x = %d push_n = %d\n", push_x, push_n);
	fprintf(fp, "col.s %d row.s %d num_stars = %d\n", tet->del_col_s, tet->del_row_s, tet->num_stars); //oo
	while (i < tet->index) //llop out
	{
		fprintf(fp, "tet->cordis[%d].%d.%d -> tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n, i, tet->cordis[i].x + push_x, tet->cordis[i].n + push_n);
		i++;
	}
	fclose(fp);
	if ((compare(ptr, tet, push_x, push_n)) == 1)
		place(ptr, tet, push_x, push_n);
	return (ptr);
}


static t_filler		*q_left(t_filler *ptr, t_tetra *tet)
{
	int push_x;
	int push_n;
	FILE *fp;
	int i = 0;
	fp = fopen("left", "w");
	fprintf(fp, "\nme_s.%d.%d\n", ptr->me_s.x, ptr->me_s.n);
	fprintf(fp, "\ntet->r.%d.%d\n", tet->r.x, tet->r.n);
	fprintf(fp, "q = %d", ptr->q);
	push_x = ptr->me_s.x - tet->l.x; // most right
	push_n = ptr->me_s.n - tet->l.n;
	fprintf(fp, "push_x = %d push_n = %d\n", push_x, push_n);
	fprintf(fp, "col.s %d row.s %d num_stars = %d\n", tet->del_col_s, tet->del_row_s, tet->num_stars); //oo
	while (i < tet->index) //llop out
	{
		fprintf(fp, "tet->cordis[%d].%d.%d -> tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n, i, tet->cordis[i].x + push_x, tet->cordis[i].n + push_n);
		i++;
	}
	fclose(fp);
	if ((compare(ptr, tet, push_x, push_n)) == 1)
		place(ptr, tet, push_x, push_n);
	return (ptr);
}

t_filler		*algo(t_filler *ptr, t_tetra *tet)
{
	if (ptr->q == 4 || ptr->q == 2)
		q_right(ptr, tet);
	else if (ptr->q == 1 || ptr->q == 3)
		q_left(ptr, tet);
	return (ptr);
}
