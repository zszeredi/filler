/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/26 16:50:10 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr(char const *s, int n)
{
	int	index;
	int	counter;
	int	len;

	len = ft_strlen(s);
	counter = 0;
	if (n > len)
		counter = ft_putstr_len(s);
	else
	{
		index = 0;
		while (s[index] != '\0')
		{
			while (index < n)
			{
				write(1, &s[index], 1);
				counter++;
				index++;
			}
			break ;
		}
	}
	return (counter);
}
