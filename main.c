#include "filler.h"

int main(void)
{
	t_filler	*ptr;
	FILE		*fp;
	int			i;
	static		int counter;
	i = 0;
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
	ptr->counter = 0;
	while (get_next_line(0, &ptr->line) > 0)
	{
		if(ft_strstr(ptr->line, "Plateau") != NULL)
		{
			get_next_line(0, &ptr->line);
			counter = 1;
		}
		fill_up(ptr, counter);
		tetro_read(ptr, ptr->line);
		ft_putnbr(ptr->sb.n);
		ft_putchar(' ');
		ft_putnbr(ptr->sb.x);
		ft_putchar('\n');
		ft_strdel(&ptr->line);
		//	printf("%d %d\n", ptr->me_s.n, ptr->me_s.x);
	}
	fclose(fp);
	free(ptr->line);
	delete_table(ptr->table, ptr);
	free(ptr);
	return (0);
}
