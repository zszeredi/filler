#include "filler.h"

t_table		*place(t_filler *ptr, t_table *t, t_tetra *tet, int x, int n)
{
	int i;
	int m;
	int j;
	int a;
	int b;
	FILE *fp;
	m = 0;
	i = 0;
	fp = fopen("newtable", "a");
	fprintf(fp, "hello\n");
	while(i < tet->index)
	{
		b = tet->cordis[i].x + x;
		a = tet->cordis[i].n + n;
		if (i == 0)
		{
			t->me_s.x = b;
			t->me_s.n = n;
		}
		fprintf(fp, "%d %d\n", b, a);
		t->table[a][b] = ptr->me + 32;
		i++;
	}
	fclose(fp);
	fp = fopen("new", "w");
	while (m < ptr->lines) //loop out
	{
		j = 0;
		while (j <= ptr->columns)
		{
			fprintf(fp, "%c", t->table[m][j]);
			j++;
		}
		fprintf(fp, "m\n");
		m++;
	}
	fprintf(fp, "\nme_s.%d.%d\n", t->me_s.x, t->me_s.n);
	fclose(fp);
	return (t);
}

int 		compare(t_table *t, t_tetra *tet, int x, int n)
{
	int i;

	i = 0;
	while (i < tet->index)
	{
		if (t->table[tet->cordis[i].x + x][tet->cordis[i].n + n] == '.')
			i++;
		else
			return (-1);
	}
	return (1);
}

static int		q_right(t_filler *ptr, t_table *t, t_tetra *tet)
{
	int push_x;
	int push_n;
	FILE *fp;
	int i = 0;
	fp = fopen("right", "w");
	fprintf(fp, "\nme_s.%d.%d\n", t->me_s.x, t->me_s.n);
	fprintf(fp, "\ntet->r.%d.%d\n", tet->r.x, tet->r.n);
	fprintf(fp, "q = %d", ptr->q);
	push_x = t->me_s.x - tet->r.x; // most right
	push_n = t->me_s.n - tet->r.n;
	fprintf(fp, "push_x = %d push_n = %d\n", push_x, push_n);
	fprintf(fp, "col.s %d row.s %d num_stars = %d\n", tet->del_col_s, tet->del_row_s, tet->num_stars); //oo
	while ( i < tet->index) //llop out
	{
		fprintf(fp, "tet->cordis[%d].%d.%d -> tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n, i, tet->cordis[i].x + push_x, tet->cordis[i].n + push_n);
		i++;
	}
	fclose(fp);
	if ((compare(t, tet, push_x, push_n)) == 1)
		place(ptr, t, tet, push_x, push_n);
	return (1);
}


static int		q_left(t_filler *ptr, t_table *t, t_tetra *tet)
{
	int push_x;
	int push_n;
	FILE *fp;
	int i = 0;
	fp = fopen("left", "w");
	fprintf(fp, "\nme_s.%d.%d\n", t->me_s.x, t->me_s.n);
	fprintf(fp, "\ntet->r.%d.%d\n", tet->r.x, tet->r.n);
	fprintf(fp, "q = %d", ptr->q);
	push_x = t->me_s.x - tet->l.x; // most right
	push_n = t->me_s.n - tet->l.n;
	fprintf(fp, "push_x = %d push_n = %d\n", push_x, push_n);
	fprintf(fp, "col.s %d row.s %d num_stars = %d\n", tet->del_col_s, tet->del_row_s, tet->num_stars); //oo
	while ( i < tet->index) //llop out
	{
		fprintf(fp, "tet->cordis[%d].%d.%d -> tet->cordis[%d].%d.%d\n", i, tet->cordis[i].x, tet->cordis[i].n, i, tet->cordis[i].x + push_x, tet->cordis[i].n + push_n);
		i++;
	}
	fclose(fp);
	if ((compare(t, tet, push_x, push_n)) == 1)
		place(ptr, t, tet, push_x, push_n);
	return (1);
}

t_table			*algo(t_filler *ptr, t_table *t, t_tetra *tet)
{
	int fin;

	fin = 0;
	if (ptr->q == 4 || ptr->q == 2)
		fin = q_right(ptr, t, tet);
	else if (ptr->q == 1 || ptr->q == 3)
		fin = q_left(ptr, t, tet);
	/*if (fin == 1)
		printf("[%d, %d]", t->me_s.n, t->me_s.x);
	else
		printf("[0, 0]");
*/	return (t);
}
