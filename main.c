#include "filler.h"

int main(void)
{
	t_filler	*ptr;
	FILE		*fp;
	fp = fopen("text", "a");
	if (!(ptr = malloc(sizeof(t_filler))))
		return (-1);
	if (get_next_line(0, &ptr->line) > 0)
	{
		fprintf(fp, "line = %s\n", ptr->line);
		get_player(ptr);
	}
	ft_strdel(&ptr->line);
	if (get_next_line(0, &ptr->line) > 0)
	{
		fprintf(fp, "line = %s\n", ptr->line);
		create_table(ptr, ptr->line);
	}
		ft_strdel(&ptr->line);
	fclose(fp);
	ptr->q = 0;
	ptr->counter = -1;
	ptr->intersection = 0;
	ptr->wall = 0;
	fprintf(fp, "ptr->me = %c\n", ptr->me);
	while (get_next_line(0, &ptr->line) > 0)
	{
		if(ft_strstr(ptr->line, "Plateau") != NULL)
			get_next_line(0, &ptr->line);
		fill_up(ptr);
		tetro_read(ptr, ptr->line);
		ft_putnbr(ptr->coo.n);
		ft_putchar(' ');
		ft_putnbr(ptr->coo.x);
		ft_putchar('\n');
		//	printf("%d %d\n", ptr->me_s.n, ptr->me_s.x);
	}
	fclose(fp);
	delete_table(ptr->table, ptr);
	free(ptr);
	return (0);
}
