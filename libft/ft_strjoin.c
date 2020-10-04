/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:22:11 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/17 18:17:02 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*start;
	size_t	len;
	size_t	len2;

	if (s1 && s2)
	{
		len = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(start = (char *)malloc(sizeof(char) * ((len + len2) + 1))))
			return (NULL);
		ft_strcpy(start, s1);
		ft_strcat(start, s2);
		return (start);
	}
	return (NULL);
}
