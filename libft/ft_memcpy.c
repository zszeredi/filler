/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:13:34 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 16:26:20 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	while (dst != NULL || src != NULL)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return ((void *)dst);
	}
	return (NULL);
}
