/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:31:43 by zszeredi          #+#    #+#             */
/*   Updated: 2020/08/30 09:46:39 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base_calc(t_itoa *p, unsigned int num, char *buffer, int base)
{
	while (p->len-- > p->min)
	{
		p->sum = num % base;
		if (p->sum > 9)
			buffer[p->len] = p->sum - 10 + p->cap;
		else
			buffer[p->len] = p->sum + 48;
		num /= base;
	}
	return (buffer);
}

size_t	ft_uitoa_base_len(unsigned int num, int base)
{
	size_t	counter;

	if (num == 0)
		return (1);
	counter = 0;
	while (num)
	{
		num /= base;
		counter++;
	}
	return (counter);
}

char	*ft_uitoa_base(unsigned int num, int base, int cap)
{
	t_itoa	*p;
	char	*buffer;

	if (!(p = malloc(sizeof(t_itoa))))
		return (NULL);
	p->len = ft_uitoa_base_len(num, base);
	p->min = 0;
	if (base < 2 || base > 36)
		return (NULL);
	if (!(buffer = malloc(sizeof(char) * p->len + 1)))
		return (NULL);
	buffer[p->len] = '\0';
	if (cap == 1)
		p->cap = 65;
	else
		p->cap = 97;
	if (num == 0)
		buffer[0] = '0';
	else
		ft_uitoa_base_calc(p, num, buffer, base);
	free(p);
	return (buffer);
}
