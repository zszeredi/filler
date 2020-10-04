/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:30:58 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/17 18:21:58 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	int		len;

	len = ft_strlen(s);
	c2 = (char)c;
	while (len != -1 && s[len] != c2)
		len--;
	if (s[len] == c2)
		return ((char*)&s[len]);
	return (NULL);
}
