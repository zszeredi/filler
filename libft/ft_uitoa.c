/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:22:52 by zszeredi          #+#    #+#             */
/*   Updated: 2020/08/30 09:42:51 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uitoa_len(unsigned int num)
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

char	*ft_uitoa(unsigned int num)
{
	int		l;
	char	*r;

	l = ft_uitoa_len(num);
	if (!(r = (char *)malloc(l + 1)))
		return (NULL);
	r[l] = '\0';
	while (l-- > 0)
	{
		r[l] = '0' + num % 10 * 1;
		num /= 10;
	}
	return (r);
}
