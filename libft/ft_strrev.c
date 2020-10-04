/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:42:55 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 13:46:18 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	size_t	i;
	size_t	len;
	char	temp;
	char	*cstr;

	cstr = (char *)str;
	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = cstr[i];
		cstr[i] = cstr[(len - i) - 1];
		cstr[(len - i) - 1] = temp;
		i++;
	}
	return (cstr);
}
