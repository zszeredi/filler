/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:50:04 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 12:34:04 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	end;

	if (!s)
		return (NULL);
	i = 0;
	end = ft_strlen(s);
	while (((s[i] == 32) || (s[i] == 10) || (s[i] == 9)) && (s[i] != '\0'))
		i++;
	while (((s[end - 1] == 32) || (s[end - 1] == 10) ||
				(s[end - 1] == 9)) && (s[i] != '\0'))
		end--;
	if (i == end)
		return (ft_strnew(1));
	len = end - i;
	return (ft_strsub(s, i, len));
}
