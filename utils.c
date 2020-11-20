#include "filler.h"

t_coords		coord_copy(t_coords coo, int j, int i)
{
	coo.x = j;
	coo.n = i;
	return (coo);
}