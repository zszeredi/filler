#include "filler.h"

int main(void)
{
	char *line;
	t_filler *ptr;
	t_table *t;
	FILE *fp;
	if(!(ptr = malloc(sizeof(t_filler))))
		return (-1);
	if (!(t = malloc(sizeof(t_table))))
		return (-1);
	if((get_next_line(0, &line)) == 1)
		ptr = get_player(line, ptr);
	if((get_next_line(0, &line)) == 1)
		ptr = get_table_size(line, ptr);
	t = create_table(ptr, t);
	fp = fopen("w.txt", "a");
	fprintf(fp, "hello");
	fclose(fp);
	return (0);
}
