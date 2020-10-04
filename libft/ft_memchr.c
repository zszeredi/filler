/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:07:49 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 11:52:31 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c2)
			return ((void *)&str[i]);
		else
			i++;
	}
	return (NULL);
}
