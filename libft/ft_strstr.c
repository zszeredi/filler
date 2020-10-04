/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:11:11 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 12:03:05 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (haystack[i] != '\0' && needle[j] != '\0'
				&& haystack[i] == needle[j])
		{
			j++;
			i++;
		}
		if (needle[j] == '\0')
			return (&str[k]);
		i = k;
		i++;
	}
	return (0);
}
