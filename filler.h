/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 09:40:06 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/10 15:17:49 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_filler
{
	int			columns;
	int			lines;
	int			q;
	char		me;
	char		opp;
}				t_filler;

typedef struct	s_coords
{
	int x;
	int n;
}				t_coords;

typedef struct	s_table
{
	char		**table;
	t_coords	me_s;
	t_coords	coo;
}				t_table;
typedef	struct	s_tetra
{
	int			del_col_s;
	int			del_row_s;
	int			t_col;
	int			t_lin;
	int			num_stars;
	int			index;
	char		**tetra;
	t_coords	l;
	t_coords	r;
	t_coords	*cordis;

}				t_tetra;
t_table			*delete_table(char **str, t_table *t);
t_table			*algo(t_filler *ptr, t_table *t, t_tetra *tet);
t_tetra			*cut_off(t_tetra *tet);
t_coords		coord_copy(t_coords coo, int i, int j);
t_tetra			*tetro_read(t_filler *ptr, t_table *t, t_tetra *tet);
t_filler		*quadrant(t_filler *ptr, t_table *t);
t_table			*fill_up(t_filler *ptr, t_table *t);
t_table			*create_table(t_filler *ptr, t_table *t);
t_filler		*get_table_size(char *line, t_filler *ptr);
t_filler		*get_player(char *line, t_filler *ptr);
t_table			*first_round(t_filler *ptr, t_table *t, char *line);
int				main(void);
#endif
