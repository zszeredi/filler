/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:37:30 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/17 18:23:50 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		j = 0;
		if (!(s2 = (char *)malloc(sizeof(*s2) * (len + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			s2[j] = f(i, s[i]);
			i++;
			j++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
