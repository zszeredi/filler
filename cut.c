#include "filler.h"

static int		cut_off_lin(t_tetra *tet, int n)
{
	int x;
	int counter;

	x = 0;
	counter = 0;
	while (x < tet->t_col &&  n < tet->t_lin && n >= 0)
	{
		if (tet->tetra[n][x] == '*')
			return (counter);
		if (x == tet->t_col - 1)
		{
			counter++;
			x = 0;
			n++;
		}
		else
			x++;
	}
	return(counter);
}

static int		cut_off_col(t_tetra *tet, int x)
{
	int n;
	int counter;

	n = 0;
	counter = 0;
	while (n < tet->t_lin && x < tet->t_col && x >= 0)
	{
		if (tet->tetra[n][x] == '*')
			return (counter);
		if (n == tet->t_lin - 1)
		{
			counter++;
			n = 0;
			x++;
		}
		else
			n++;
	}
	return(counter);
}

t_tetra			*cut_off(t_tetra *tet)
{
	tet->del_col_s = 0;
	tet->del_row_s = 0;
	tet->del_col_s = cut_off_col(tet, 0);
	tet->del_row_s = cut_off_lin(tet, 0);
	return (tet);
}
