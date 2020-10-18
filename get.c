/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:19:31 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/09 20:00:49 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler 	*quadrant(t_filler *ptr, t_table *t)
{
	int ud;
	int lr;
	if (t->me_s.x < ptr->columns / 2)
		lr = 1;
	else
		lr = 2;
	if (t->me_s.n < ptr->lines / 2)
		ud = 1;
	else
		ud = 2;
	if (lr == 1 && ud == 1)
		ptr->q = 1;
	if (lr == 2 && ud == 1)
		ptr->q = 2;
	if (lr == 1 && ud == 2)
		ptr->q = 3;
	if (lr == 2 && ud == 2)
		ptr->q = 4;
	return (ptr);
}
t_filler	*get_table_size(char *line, t_filler *ptr)
{
	char **sizes;

	sizes = ft_strsplit(line, ' ');
	ptr->lines = ft_atoi(sizes[1]);
	ptr->columns = ft_atoi(sizes[2]);
	ft_strdel(sizes);
	return (ptr);
}

t_filler	*get_player(char *line, t_filler *ptr)
{
	if ((ft_strstr(line, "p1")) != 0)
	{
		ptr->me = 'O';
		ptr->opp = 'X';
	}
	else
	{
		ptr->me = 'X';
		ptr->opp = 'O';
	}
	return (ptr);
}
