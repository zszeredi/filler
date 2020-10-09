#include "filler.h"

int main(void)
{
	char *line;
	t_filler *ptr;
	t_table *t;
	FILE *fp;
	int fd;
	int m = 0;
	int j;
	line = NULL;
	printf("0 0");
	if(!(ptr = malloc(sizeof(t_filler))))
		return (-1);
	if (!(t = malloc(sizeof(t_table))))
		return (-1);
	fp = fopen("text", "a");
	if (line == NULL)
	{
		get_next_line(0, &line);
		ptr = get_player(line, ptr);
		fprintf(fp, "%s\n", line);
		fprintf(fp, "%c %c\n", ptr->me, ptr->opp);
		get_next_line(0, &line);
		ptr = get_table_size(line, ptr);
		fprintf(fp, "%s\n", line);
		fprintf(fp, "%d %d\n", ptr->lines, ptr->columns);
		t = create_table(ptr, t);
	//	while ((ft_strstr(line, "Piece")) == 0)
	//		get_next_line(0, &line);
		while (m < ptr->lines)
		{
			j = 0;
			while (j <= ptr->columns)
			{
				fprintf(fp, "%c", t->table[m][j]);
				j++;
			}
			fprintf(fp, "n\n");
			m++;
		}

			fclose(fp);
	}
	/*		
			if((get_next_line(0, &line)) == 1)
			fprintf(fp, "hello");
			*/
	free(line);	
	fclose(fp);
	return (0);
}
