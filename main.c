#include "filler.h"

/*t_filler	*first_round(t_filler *ptr)
  {
  FILE *fp; //
  char *line;
  int j;//
  int m = 0; //out
  fp = fopen("first", "w"); //oo//
  if (get_next_line(0, &line) > 0)
  ptr = get_player(line, ptr);
  fprintf(fp, "%s\n", line);//oo
  fprintf(fp, "%c %c\n", ptr->me, ptr->opp); //oo
  if (get_next_line(0, &line) > 0)
  ptr = get_table_size(line, ptr);
  fprintf(fp, "%s\n", line); //
  fprintf(fp, "%d %d\n", ptr->lines, ptr->columns);//o
  create_table(ptr);
  while (m < ptr->lines) //loop out
  {
  j = 0;
  while (j <= ptr->columns)
  {
  fprintf(fp, "%c", ptr->table[m][j]);
  j++;
  }
  fprintf(fp, "m\n");
  m++;
  }
  fclose(fp); //oo
  ptr = quadrant(ptr);
  free(line);
  return (ptr);
  }
  */
int main(void)
{
	t_filler	*ptr;
	
	if (!(ptr = malloc(sizeof(t_filler))))
		return (-1);
	if (get_next_line(0, &ptr->line) > 0)
		get_player(ptr);
		ft_strdel(&ptr->line);
	if (get_next_line(0, &ptr->line) > 0)
		create_table(ptr, ptr->line);
	ft_strdel(&ptr->line);
	while (get_next_line(0, &ptr->line) > 0)
	{
		fill_up(ptr);
			tetro_read(ptr, ptr->line);
		ft_putnbr(ptr->me_s.n);
		ft_putchar(' ');
		ft_putnbr(ptr->me_s.x);
		ft_putchar('\n');
	//	printf("%d %d\n", ptr->me_s.n, ptr->me_s.x);
	}
	free(ptr->line);
	delete_table(ptr->table, ptr);
	free(ptr);
	return (0);
}
