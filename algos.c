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
			ptr->coo = coord_copy(ptr->coo, x - tet->del_col_s, n - tet->del_row_s);
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
	int counter;

	i = 0;
	counter = 0;
	while (i < tet->index)
	{
		b = tet->cordis[i].x + x;
		a = tet->cordis[i].n + n;
		if (a < 0 || b < 0 || b > ptr->columns - 2 || a > ptr->lines - 1)
			return (-1);
		if ((ptr->table[a][b] == ptr->opp) || counter > 1)
			return (-1);
		else if (ptr->table[a][b] != '.')
			counter++;
		i++;
	}
	if (counter > 1 || counter < 1)
		return (-1);
	return (1);
}

t_tetra			*push_ud(t_filler *ptr, t_tetra *tet, int i)
{
	ext_coords(tet, i);
	if (ptr->q == 4 || ptr->q == 2)
	{
		tet->push_x = ptr->up.x - tet->r.x;
		tet->push_n = ptr->up.n - tet->r.n;

	}
	else if (ptr->q == 1 || ptr->q == 3)
	{
		tet->push_x = ptr->down.x - tet->l.x;
		tet->push_n = ptr->down.n - tet->l.n;

	}
	return (tet);
}

t_tetra 		*push_calc(t_tetra *tet, int index, int i, int j)
{
	tet->push_x = j - tet->cordis[index].x;
	tet->push_n = i - tet->cordis[index].n;
	return (tet);
}


int 			find_place_down(t_filler *ptr, t_tetra *tet)
{
	int i;
	int j;
	int index;

	i = ptr->down.n;
	j = ptr->down.x;
	while (i > 0)
	{
		while (j > 0)
		{
			if (ptr->table[i][j] == ptr->me)
			{
				index = 0;
				while (index < tet->num_stars)
				{
					push_calc(tet, index, i, j); // SEPERATE FUNC
					if (compare(ptr, tet, tet->push_x, tet->push_n) == 1)
					{
						place(ptr, tet, tet->push_x, tet->push_n);
						return (1);
					}
					index++;
				}
			}
			j--;
		}
		i--;
		j = ptr->columns;
	}
	ptr->coo = coord_copy(ptr->coo, 0, 0);
	ptr->end = 1;
	return  (-1);
}

int 			find_place_up(t_filler *ptr, t_tetra *tet)
{
	int i;
	int j;
	int index;

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
					push_calc(tet, index, i, j);
					if (compare(ptr, tet, tet->push_x, tet->push_n) == 1)
					{
						place(ptr, tet, tet->push_x, tet->push_n);
						return (1);
					}
					index++;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
	ptr->coo = coord_copy(ptr->coo, 0, 0);
	ptr->end = 1;
	return  (-1);
}

t_filler		*algo(t_filler *ptr, t_tetra *tet)
{
	push_ud(ptr, tet, 0);
	if (compare(ptr, tet, tet->push_x, tet->push_n) < 1)
	{
		if (ptr->q == 4)
			find_place_up(ptr, tet);
		else
			find_place_down(ptr, tet);
	}
	else
		place(ptr, tet, tet->push_x, tet->push_n);
	return (ptr);
}