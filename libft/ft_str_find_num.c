/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:30:15 by zszeredi          #+#    #+#             */
/*   Updated: 2020/08/18 09:30:35 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_find_num(char *str)
{
	size_t	i;
	int		counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			counter++;
		i++;
	}
	if (counter > 0)
		return (1);
	if (*str == '\0')
		return (0);
	return (0);
}
