/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 09:28:58 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 14:33:46 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_parse		*f_set_param(t_parse *p, long double num)
{
	if ((p->f_plus == 1 || num < 0) && p->f_space == 1)
		p->f_space = 0;
	if (num < 0)
		p->f_plus = 0;
	if (p->f_minus == 1 && p->f_zero == 1)
		p->f_zero = 0;
	if (p->precision <= -1)
		p->precision = 6;
	if (p->precision > 0 || p->precision == -1)
		p->f_hash = 0;
	return (p);
}

static t_for_f		*f_modifier(t_parse *p, t_s_to_fs *pointer, t_for_f *ptr)
{
	if (p->ls == 76 || p->ls == 108)
		ptr->num = (long double)va_arg(pointer->ap, long double);
	else
		ptr->num = (double)va_arg(pointer->ap, double);
	if (ptr->num <= DBL_MAX || ptr->num >= DBL_MIN)
		ptr->num = (double)ptr->num;
	if (ptr->num > DBL_MAX)
		ptr->num = (long double)ptr->num;
	return (ptr);
}

int					ft_f_fs(t_parse *p, t_s_to_fs *pointer)
{
	t_for_f	*ptr;

	if (!(ptr = malloc(sizeof(t_for_f))))
		return (-1);
	f_modifier(p, pointer, ptr);
	ptr->neg = ptr->num < 0 ? 1 : 0;
	f_set_param(p, ptr->num);
	round_up(p, ptr);
	ptr->len = len(p, ptr->d, ptr->neg);
	if (p->width > ptr->len)
	{
		ptr->space = p->width - ptr->len;
		if (p->f_minus == 0)
			printf_no_min(p, pointer, ptr);
		else
		{
			print_f(p, pointer, ptr);
			ft_print_space(p, pointer, ptr->space, 1);
		}
	}
	else
		print_f(p, pointer, ptr);
	free(ptr);
	return (pointer->counter);
}
