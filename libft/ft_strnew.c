/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:32:37 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/06 17:38:41 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
