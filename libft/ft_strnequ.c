/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:49:30 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/17 18:26:43 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2 && n)
	{
		while (i < n)
		{
			if (s1 == s2)
				return (1);
			if (n == 0)
				return (0);
			while (((s1[i] != '\0') && (s2[i] != '\0') &&
						(s1[i] != s2[i])) || i < n - 1)
			{
				if (s1[i] != s2[i])
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (1);
}
