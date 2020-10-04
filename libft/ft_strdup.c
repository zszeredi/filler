/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:33:29 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 11:55:11 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)s1;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		ft_strcpy(dest, s1);
	}
	return (dest);
	free(dest);
}
