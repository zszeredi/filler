/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:51:22 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/24 14:04:45 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		delete_double_array(char **str)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
}

void	get_table_size(char *line, int x, int y)
{
	char **sizes;

	sizes = ft_strsplit(line, ' ');
	x = ft_atoi(sizes[1]);
	y = ft_atoi(sizes[2]);
	ft_strdel(sizes);
}