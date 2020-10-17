#include "filler.h"

static int		cut_off_lin(t_tetra *tet, int n, int cal)
{
	int x;
	int counter;

	x = 0;
	counter = 0;
	while (x < tet->col &&  n < tet->lin && n >= 0)
	{
		if (tet->tetra[n][x] == '*')
			return (counter);
		if (x == tet->col - 1)
		{
			counter++;
			x = 0;
			cal > 0 ? n++ : n--;
		}
		else
			x++;
	}
	return(counter);
}

static int		cut_off_col(t_tetra *tet, int x, int cal)
{
	int n;
	int counter;

	n = 0;
	counter = 0;
	while (n < tet->lin && x < tet->col && x >= 0)
	{
		if (tet->tetra[n][x] == '*')
			return (counter);
		if (n == tet->lin - 1)
		{
			counter++;
			n = 0;
			cal == 1 ? x++ : x--;
		}
		else
			n++;
	}
	return(counter);
}

t_tetra			*cut_off(t_tetra *tet)
{
	tet->del_col_s = 0;
	tet->del_col_e = 0;
	tet->del_row_s = 0;
	tet->del_row_e = 0;
	tet->del_col_s = cut_off_col(tet, 0, 1);
	tet->del_col_e = cut_off_col(tet, tet->col - 1, 0);
	tet->del_row_s = cut_off_lin(tet, 0, 1);
	tet->del_row_e = cut_off_lin(tet, tet->lin - 1, 0);
	return (tet);
}
