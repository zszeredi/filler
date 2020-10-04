/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_next_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 08:51:40 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/13 13:18:23 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_next_chr(const char *s, int c, int n)
{
	int		i;
	char	c2;
	char	n2;

	i = 0;
	c2 = (char)c;
	n2 = (char)n;
	while (s[i] != c2)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	if (i > 0 && s[i - 1] == n2)
		return (1);
	else if (s[i + 1] != '\0' && s[i + 1] == n2)
		return (2);
	return (0);
}
