#include "filler.h"

t_table *first_round(t_filler *ptr, t_table *t, char *line)
{
	FILE *fp; //
	int j;//
	int m = 0; //out
	if (!(t = malloc(sizeof(t_table))))
		return (NULL);
	fp = fopen("first", "w"); //oo//
	get_next_line(0, &line);
	ptr = get_player(line, ptr);
	fprintf(fp, "%s\n", line);//oo
	fprintf(fp, "%c %c\n", ptr->me, ptr->opp); //oo
	get_next_line(0, &line);
	ptr = get_table_size(line, ptr);
	fprintf(fp, "%s\n", line); //
	fprintf(fp, "%d %d\n", ptr->lines, ptr->columns);//o
	t = create_table(ptr, t);
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
	fclose(fp); //oo
	ptr = quadrant(ptr, t);
	return (t);
}

int main(void)
{
	printf("0,0\n");
	char *line;
	int n;
	t_filler *ptr;
	t_table *t;
	t_tetra *tet;
	if (!(tet = malloc(sizeof(t_tetra))))
		return (-1);
	n = 0;
	if (n == 0)
	{
		if (!(ptr = malloc(sizeof(t_filler))))
			return (-1);

		t = first_round(ptr, t, line);
		tet = tetro_read(ptr, t, tet);
		n = 1;
	}
	else
	{
		fill_up(ptr, t);
		tet = tetro_read(ptr, t, tet);
	}
	//printf("%d %d", tet->cordis[0].x, tet->cordis[0].n);
	return (0);
}
