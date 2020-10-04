/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:33:37 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/13 20:49:59 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char			*start;
	unsigned int	len;
	unsigned int	len2;

	if (s1 && s2)
	{
		len = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(start = (char *)malloc(sizeof(char) * ((len + len2) + 1))))
			return (NULL);
		ft_strcpy(start, s1);
		ft_strcat(start, s2);
		free(s1);
		return (start);
	}
	return (NULL);
}
