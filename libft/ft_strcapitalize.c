/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:58:00 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 13:08:08 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	index;
	size_t	upper;

	index = 0;
	upper = 1;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'a' && str[index] <= 'z') || (str[index] >= 'A'
					&& str[index] <= 'Z') ||
				(str[index] >= '0' && str[index] <= '9'))
		{
			if (upper && (str[index] >= 'a' && str[index] <= 'z'))
				str[index] = str[index] - 32;
			else if (!upper && (str[index] >= 'A' && str[index] <= 'Z'))
				str[index] = str[index] + 32;
			upper = 0;
		}
		else
			upper = 1;
		index++;
	}
	return (str);
}
