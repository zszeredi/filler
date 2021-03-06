/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 09:40:06 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/07 16:37:16 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include "libft/libft.h"
# include <stdint.h>
# include <unistd.h>
# include <string.h>
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
	int 		end;
	int			counter;
	int 		me_line;
	int			opp_line;
	int			intersection;
	char		me;
	char		opp;
	char		*line;
	char		**table;
	t_coords	me_s;
	t_coords	up;
	t_coords	down;
	t_coords	coo;

}				t_filler;

typedef	struct	s_tetra
{
	int			del_col_s;
	int			del_row_s;
	int			t_col;
	int			t_lin;
	int			num_stars;
	int			index;
	int			push_x;
	int			push_n;
	char		**tetra;
	t_coords	l;
	t_coords	r;
	t_coords	u;
	t_coords	d;
	t_coords	*cordis;

}				t_tetra;

char 			*delete_double_array(char **str, int n);
t_coords		coord_copy(t_coords coo, int i, int j);
t_filler		*place(t_filler *ptr, t_tetra *tet, int x, int n);
int				compare(t_filler *ptr, t_tetra *tet, int x, int n);
t_filler		*algo(t_filler *ptr, t_tetra *tet);
t_tetra			*cut_off(t_tetra *tet);
t_coords		coord_copy(t_coords coo, int i, int j);
t_tetra 		*ext_coords(t_tetra *tet, int n);
t_filler		*tetro_read(t_filler *ptr, char *line);
int				quadrant(t_filler *ptr);
t_filler		*fill_up(t_filler *ptr);
t_filler		*create_table(t_filler *ptr, char *line);
t_filler		*get_player(t_filler *ptr);
int				main(void);
#endif
