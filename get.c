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
