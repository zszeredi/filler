/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:23:53 by zszeredi          #+#    #+#             */
/*   Updated: 2020/08/18 09:24:15 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ll_itoa_len(long long n)
{
	size_t	r;

	if (n == 0)
		return (1);
	r = 0;
	if (n < 0)
		r++;
	while (n)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char	*ft_ll_itoa(long long n)
{
	int		l;
	int		e;
	char	*r;

	l = ft_ll_itoa_len(n);
	if (!(r = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	r[l] = '\0';
	if (n < 0)
	{
		r[0] = '-';
		e = 1;
	}
	else
		e = 0;
	while (l-- > e)
	{
		r[l] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (r);
}
