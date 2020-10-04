/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/08/30 09:45:30 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_base_calc(t_itoa *p, int num, char *buffer, int base)
{
	if (num < 0)
	{
		num *= -1;
		if (base == 10)
		{
			buffer[0] = '-';
			p->min = 1;
		}
	}
	while (p->len-- > p->min)
	{
		p->sum = num % base;
		if (p->sum > 9)
			buffer[p->len] = p->sum - 10 + 97;
		else
			buffer[p->len] = p->sum + 48;
		num /= base;
	}
	return (buffer);
}

static size_t	ft_itoa_base_len(int num, int base)
{
	size_t	counter;

	if (num == 0)
		return (1);
	counter = 0;
	if (num < 0 && base == 10)
		counter++;
	while (num)
	{
		num /= base;
		counter++;
	}
	return (counter);
}

char			*ft_itoa_base(int num, int base)
{
	t_itoa	*p;
	char	*buffer;

	if (!(p = malloc(sizeof(t_itoa))))
		return (NULL);
	p->len = ft_itoa_base_len(num, base);
	p->min = 0;
	if (base < 2 || base > 36)
		return (NULL);
	if (!(buffer = malloc(sizeof(char) * p->len + 1)))
		return (NULL);
	buffer[p->len] = '\0';
	if (num == 0)
		buffer[0] = '0';
	else
		ft_itoa_base_calc(p, num, buffer, base);
	free(p);
	return (buffer);
}
