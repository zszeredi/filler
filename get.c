/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:19:31 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/25 09:54:50 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

 int		quadrant(t_filler *ptr)
{
	int ud;
	int lr;
	FILE *fp;

	fp = fopen("quad", "w");
	if (ptr->columns / 2 > ptr->me_s.x)
		lr = 1;
	else
		lr = 2;
	if (ptr->lines / 2 > ptr->me_s.n)
		ud = 1;
	else
		ud = 2;
	fprintf(fp, "%d %d\n", lr, ud);
	if (lr == 1 && ud == 1)
		ptr->q = 1;
	if (lr == 2 && ud == 1)
		ptr->q = 2;
	if (lr == 1 && ud == 2)
		ptr->q = 3;
	if (lr == 2 && ud == 2)
		ptr->q = 4;
	return (ptr->q);
}

t_filler	*get_player(t_filler *ptr)
{
	if (ptr->line[10] == 49)
	{
		ptr->me = 79;
		ptr->opp = 88;
	}
	else
	{
		ptr->me = 88;
		ptr->opp = 79;
	}
	return (ptr);
}
