#include "filler.h"

int main(void)
{
	char *line;
	t_filler *ptr;
	t_table *t;
	t_tetra *tet;
	FILE *fp; //o
	int m = 0;//o
	int j;//o
	line = NULL;
	printf("0 0"); //00
	if(!(ptr = malloc(sizeof(t_filler))))
		return (-1);
	if (!(t = malloc(sizeof(t_table))))
		return (-1);
	if (!(tet = malloc(sizeof(t_tetra))))
		return (-1);
	fp = fopen("text", "w"); //oo
	if (line == NULL)
	{
		get_next_line(0, &line);
		ptr = get_player(line, ptr);
		fprintf(fp, "%s\n", line);//oo
		fprintf(fp, "%c %c\n", ptr->me, ptr->opp); //oo
		get_next_line(0, &line);
		ptr = get_table_size(line, ptr);
		fprintf(fp, "%s\n", line); //o
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
		tet = tetro_read(ptr, t, tet);
	}
	free(line);	
	fclose(fp); //o
	return (0);
}
