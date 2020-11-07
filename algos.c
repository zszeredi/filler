#include "filler.h"

t_tetra			*push_by(t_filler *ptr, t_tetra *tet)
{
	FILE *fp;

	fp = fopen("text", "a");
	if (ptr->strat == 0)
	{
		if (ptr->q == 4 || ptr->q ==2)
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
	}
	else if (ptr->strat == 1)
	{

		fprintf(fp, "me %d > %d\n", ptr->me_s.x, ptr->columns / 3);
		if (ptr->me_s.x > ptr->columns / 3 && tet->t_col < tet->t_lin)	
		{
			fprintf(fp, "CHANGING direct to right\n");
			tet->push_x = ptr->up.x - tet->r.x;
			tet->push_n = ptr->up.n - tet->r.n;

		}
		else
		{
			fprintf(fp, "CHANGING direct to left\n");
			tet->push_x = ptr->up.x - tet->r.x;
			tet->push_n = ptr->up.n - tet->r.n;
		
		}
		ptr->strat = 2; //not sure
	}
	else
	{
		fprintf(fp, "me %d > %d\n", ptr->me_s.x, ptr->columns / 3);
		if (tet->r.x < tet->r.n)
		{
			fprintf(fp, "CHANGED BASE GOIN UP RIGHT\n");
			tet->push_x = ptr->up.x - tet->l.x;
			tet->push_n = ptr->up.n - tet->l.n;
		}
		else //if (ptr->q == 1 || ptr->q == 3 || tet->t_col < tet->t_lin)
		{
			fprintf(fp, "CHANGED BASED GOING DOWN LEFT\n");
			tet->push_x = ptr->me_s.x - tet->r.x;
			tet->push_n = ptr->me_s.n - tet->r.n;
		}
	}
	fclose(fp);
	return (tet);
}

t_filler		*algo(t_filler *ptr, t_tetra *tet)
{
	FILE *fp;
	fp = fopen("text", "a");
	fprintf(fp, "tet->l %d %d tet->r %d %d\n", tet->l.n, tet->l.x, tet->r.n, tet->r.x);
	fprintf(fp, "up %d %d down %d %d left %d %d right %d %d me %d %d\n", ptr->up.n, ptr->up.x, ptr->down.n, ptr->down.x, ptr->left.n, ptr->left.x, ptr->right.n, ptr->right.x, ptr->me_s.n, ptr->me_s.x);
	fprintf(fp, "ptr->opp_line = %d STAT = %d\n", ptr->opp_line, ptr->strat);
	fclose(fp);
	fp = fopen("text", "a");
	push_by(ptr, tet);
	if ((compare(ptr, tet, tet->push_x, tet->push_n)) == 1)
		place(ptr, tet, tet->push_x, tet->push_n);
	else
		fprintf(fp, "need to push\n");
	//need one for filling up leftover space beyond col & line where my border is
	fprintf(fp, "\nSTAT = %d\n", ptr->strat);
	fprintf(fp, "ptr->sb %d %d\n", ptr->sb.n, ptr->sb.x);
	fclose(fp);
	return (ptr);
}
