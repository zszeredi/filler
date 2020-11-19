#include "filler.h"

int main(void)
{
	t_filler	*ptr;
	FILE		*fp;
	if (!(ptr = malloc(sizeof(t_filler))))
		return (-1);
	if (get_next_line(0, &ptr->line) > 0)
		get_player(ptr);
	free(ptr->line);
	if (get_next_line(0, &ptr->line) > 0)
		create_table(ptr, ptr->line);
	free(ptr->line);
	ptr->q = 0;
	ptr->counter = -1;
	ptr->intersection = 0;
	ptr->wall = 0;
	while (get_next_line(0, &ptr->line) > 0 && ptr->wall == 0)
	{
		fp = fopen("main", "a");
		if (ft_strstr(ptr->line, "Plateau") != NULL)
			get_next_line(0, &ptr->line);
		fill_up(ptr);
		tetro_read(ptr, ptr->line);
		ft_putnbr(ptr->coo.n);
		ft_putchar(' ');
		ft_putnbr(ptr->coo.x);
		ft_putchar('\n');
		fprintf(fp, "ptr->wall = %d\n", ptr->wall);
		fclose(fp);
	}
	fp = fopen("main", "a");
	fprintf(fp, "wall = 1\n");
	fclose(fp);
	if (ptr->line)
		free(ptr->line);
	delete_double_array(ptr->table, ptr->lines);
	free(ptr);
	return (0);
}
