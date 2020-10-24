/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:19:31 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/24 12:44:14 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
