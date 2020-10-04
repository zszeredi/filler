/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 11:59:11 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 16:25:50 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (dst != NULL || src != NULL)
	{
		if (s < d)
		{
			while (len-- > 0)
				d[len] = s[len];
		}
		else
		{
			while (i < len)
			{
				d[i] = s[i];
				i++;
			}
		}
		return ((void *)d);
	}
	return (NULL);
}
