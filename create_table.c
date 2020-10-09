/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:17:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/09 22:04:49 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			dot(char *s, int i)
{
	while (i > 0)
	{
		i--;
		s[i] = '.';
	}
}

static t_table		*delete_table(char **str, t_table *t)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
	return (t);
}

static int		check_chara(char *line, char c, int end)
{
	static int i;
	i = 0;

	if (end == 1)
	{
		i = 0;
		return (-1);
	}
	while (line[i] != '\0')
	{
		if (line[i] == c)
			return (i);
	}
	return (-1);
}

static t_table		*pos(t_filler *ptr, t_table *t) 
{
	FILE *fp;
	char *line;
	int		i;
	int 	num;
	int d;
	char c;
	int pos;
	fp = fopen("table", "w");
	i = -1;
	while (i <=  ptr->lines)
	{
		get_next_line(0, &line);
		fprintf(fp, "%s\n", line);
		if ((ft_strchr(line, ptr->me)) != 0)
			c = ptr->me;
		else if ((ft_strchr(line, ptr->opp)) != 0)
			c  = ptr->opp;
		num = ft_strnchr(line, c);
		while(num > 0)
		{
			pos = check_chara(line, c,  0);
			if ((ft_strchr(line, ptr->me)) != 0)
			{
				t->me_s.n = i;
				t->me_s.x = pos;
				t->table[t->me_s.n][t->me_s.x] = ptr->me;
			}
			else if ((ft_strchr(line, ptr->opp)) != 0)
			{
				t->me_s.n = i;
				t->opp_s.x = pos;
				t->table[t->opp_s.n][t->opp_s.x] = ptr->opp;
			}
			num--;
		}
		check_chara(line, c, 1);
		i++;
	}
	fprintf(fp, "s = %d %d o = %d %d", t->me_s.x,  t->me_s.n, t->opp_s.x, t->opp_s.n);
	fclose(fp);
	return (t);
}

t_table				*create_table(t_filler *ptr, t_table *t)
{
	int		i;

	i = -1;
	if (!(t->table = ft_memalloc((ptr->lines + 1) * sizeof(char*))))
		return (delete_table(t->table, t));
	while (++i < ptr->lines)
	{
		if (!(t->table[i] = ft_memalloc((ptr->columns + 1) * sizeof(char))))
			return (delete_table(t->table, t));
		else
		{
			dot(t->table[i], ptr->columns);
			dot(*t->table, ptr->lines);
		}
	}
	t = pos(ptr, t);
	return (t);
}
