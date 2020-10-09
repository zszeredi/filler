/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 09:40:06 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/09 21:20:06 by zszeredi         ###   ########.fr       */
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
	char		me;
	char		opp;
	int			columns;
	int			lines;
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
	t_coords	opp_s;
}				t_table;

t_table			*create_table(t_filler *ptr, t_table *t);
t_filler		*get_table_size(char *line, t_filler *ptr);
t_filler		*get_player(char *line, t_filler *ptr);
int				main(void);
#endif
