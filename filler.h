/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 09:40:06 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/06 21:00:07 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct	s_coords
{
	int x;
	int n;
}				t_coords;

typedef	struct	s_filler
{
	int			columns;
	int			lines;
	int			q;
	char		me;
	char		opp;
	char		*line;
	char		**table;
	t_coords	me_s;
	t_coords	coo;
	t_coords	sb;
	int			counter;

}				t_filler;

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
t_filler			*delete_table(char **str, t_filler *ptr);
t_filler		*algo(t_filler *ptr, t_tetra *tet);
t_tetra			*cut_off(t_tetra *tet);
t_coords		coord_copy(t_coords coo, int i, int j);
t_filler			*tetro_read(t_filler *ptr, char *line);
int				quadrant(t_filler *ptr);
t_filler		*fill_up(t_filler *ptr, int counter);
t_filler		*create_table(t_filler *ptr, char *line);
t_filler		*get_player(t_filler *ptr);
//void			get_table_size(char *line, int x, int y);
int				main(void);
#endif
