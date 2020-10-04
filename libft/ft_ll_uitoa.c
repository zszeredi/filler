/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_uitoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:20:34 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/11 18:21:58 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ll_uitoa_len(unsigned long long num)
{
	size_t	r;

	if (num == 0)
		return (1);
	r = 0;
	while (num)
	{
		num /= 10;
		r++;
	}
	return (r);
}

char	*ft_ll_uitoa(unsigned long long num)
{
	int		l;
	char	*r;

	l = ft_ll_uitoa_len(num);
	if (!(r = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	r[l] = '\0';
	while (l-- > 0)
	{
		r[l] = '0' + num % 10 * 1;
		num /= 10;
	}
	return (r);
}
