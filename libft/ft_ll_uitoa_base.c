/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_uitoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/08/18 09:22:17 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*cal(t_itoa *p, unsigned long long num, char *buffer, int base)
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

static size_t	ft_ll_uitoa_base_len(unsigned long long num, int base)
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

char			*ft_ll_uitoa_base(unsigned long long num, int base, int cap)
{
	t_itoa	*p;
	char	*buffer;

	if (!(p = malloc(sizeof(t_itoa))))
		return (NULL);
	p->len = ft_ll_uitoa_base_len(num, base);
	p->min = 0;
	if (base < 2 || base > 36)
		return (NULL);
	if (!(buffer = (char *)malloc(sizeof(char) * p->len + 1)))
		return (NULL);
	buffer[p->len] = '\0';
	if (cap == 1)
		p->cap = 65;
	else
		p->cap = 97;
	if (num == 0)
		buffer[0] = '0';
	else
		cal(p, num, buffer, base);
	free(p);
	return (buffer);
}
