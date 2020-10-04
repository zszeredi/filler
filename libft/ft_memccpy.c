/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:23:29 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 11:45:00 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	c2;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	c2 = c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c2)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
