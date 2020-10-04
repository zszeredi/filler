/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_f_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 09:39:16 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 14:41:49 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long double	next(t_for_f *ptr, long double num)
{
	num *= 10;
	ptr->d_c = (unsigned long long)num;
	ptr->next_m = num;
	ptr->next_m -= (unsigned long long)ptr->d_c;
	return (ptr->next_m);
}

static int			cm_ii(t_parse *p, t_for_f *ptr, long double num)
{
	unsigned long long	num_origin;

	num_origin = (unsigned long long)num;
	num *= 10;
	ptr->d_c = (unsigned long long)num;
	num -= ptr->d_c;
	ptr->d = ptr->d_c - (num_origin * 10);
	ptr->next_m = next(ptr, num);
	if (p->precision == 1)
	{
		if (ptr->d_c >= 5)
			ptr->counter = 0;
	}
	if (p->precision == 0 && ptr->d >= 5)
		ptr->counter = 0;
	return (ptr->counter);
}

static int			cm_i(int prec, t_for_f *ptr, long double num)
{
	while (prec > 0)
	{
		num *= 10;
		ptr->d = (unsigned long long)num;
		if (prec == 2)
		{
			ptr->next_m = next(ptr, num);
			if (ptr->next_m >= 0.5)
				ptr->counter = 0;
		}
		num -= ptr->d;
		prec--;
	}
	return (ptr->counter);
}

t_for_f				*round_up(t_parse *p, t_for_f *ptr)
{
	int		prec;
	double	deduct;

	deduct = 1.0;
	ptr->counter = 1;
	if (ptr->num < 0)
		ptr->num *= -1;
	ptr->copy = ptr->num;
	prec = p->precision;
	if (p->precision == 0 || p->precision == 1)
		ptr->counter = cm_ii(p, ptr, ptr->copy);
	else
		ptr->counter = cm_i(prec, ptr, ptr->copy);
	while (prec > 0)
	{
		deduct /= 10.0;
		prec--;
	}
	if (ptr->counter == 1)
		deduct /= 10.0;
	ptr->num += deduct;
	ptr->d = (unsigned long long)ptr->num;
	return (ptr);
}

int					len(t_parse *p, unsigned long long d, int neg)
{
	int	len;

	len = (int)ft_ll_uitoa_len(d);
	if (neg == 1)
		len++;
	if (p->f_plus == 1 || p->f_space == 1)
		len++;
	p->f_hash == 0 && p->precision == 0 ? 0 : len++;
	len += p->precision;
	return (len);
}
