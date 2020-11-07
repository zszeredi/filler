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
	while (i < tet->index && ptr->table[tet->cordis[i].x][tet->cordis[i].n + n] != '\0')
	{
		fprintf(fp, "i = %d\n", i);
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
		if (ptr->table[tet->cordis[i].x + x][tet->cordis[i].n + n] == ptr->me)
			counter++;
		i++;
	}
	fprintf(fp, "ok");
	fclose(fp);
	return (1);
}

static t_filler		*q_right(t_filler *ptr, t_tetra *tet)
{
	int push_x;
	int push_n;
	int i = 0;
	push_x = ptr->up.x - tet->r.x; // most right
	push_n = ptr->up.n - tet->r.n;
	while (i < tet->index) //llop out
		i++;
	if ((compare(ptr, tet, push_x, push_n)) == 1)
		place(ptr, tet, push_x, push_n);
	else
		return (NULL);
	return (ptr);
}


static t_filler		*q_left(t_filler *ptr, t_tetra *tet)
{
	int push_x;
	int push_n;
	int i = 0;
	if (ptr->q == 3)
	{
		push_x = ptr->down.x - tet->l.x; // most right
		push_n = ptr->down.n - tet->l.n;
	}
	while (i < tet->index) //llop out
		i++;
	if ((compare(ptr, tet, push_x, push_n)) == 1)
		place(ptr, tet, push_x, push_n);
	else
		return (NULL);
	return (ptr);
}

t_filler		*algo(t_filler *ptr, t_tetra *tet)
{
	FILE *fp;
	fp = fopen("text", "a");
	fprintf(fp, "ptr->sb %d %d\n", ptr->sb.n, ptr->sb.x);
	fprintf(fp, "q = %d\n", ptr->q);
	fprintf(fp, "tet->l %d %d tet->r %d %d\n", tet->l.n, tet->l.x, tet->r.n, tet->r.x);
	if (ptr->q == 4 || ptr->q == 2)
	{
		fprintf(fp, "right");
		if(q_right(ptr, tet) == NULL)
			fprintf(fp, "wrong");
	}
	if (ptr->q == 1 || ptr->q == 3)
	{
		fprintf(fp, "left");
		if(q_left(ptr, tet) == NULL)
			fprintf(fp, "wrong");
	}
	fprintf(fp, "ptr->sb %d %d\n", ptr->sb.n, ptr->sb.x);
	fclose(fp);
	return (ptr);
}
