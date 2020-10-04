/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:41:03 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/17 18:17:44 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		j = 0;
		if (!(s2 = (char *)malloc(sizeof(*s2) * (len + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			s2[j] = f(s[i]);
			i++;
			j++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
