/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_f_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 09:35:15 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 14:41:29 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		putf(t_parse *p, t_s_to_fs *pointer, t_for_f *ptr)
{
	char *str;

	if (!(str = ft_ll_uitoa(ptr->d)))
		return (-1);
	pointer->counter += ft_putstr_len(str);
	if (p->precision > 0 || p->f_hash == 1)
		pointer->counter += ft_putchar_len('.');
	if (ptr->num != 0.000000 && p->precision != 0)
	{
		if (p->precision != 0)
		{
			while (p->precision > 0)
			{
				ptr->num *= 10;
				ptr->d = (unsigned long long)ptr->num;
				ptr->num -= ptr->d;
				ptr->d %= 10;
				pointer->counter += ft_putchar_len(ptr->d + 48);
				p->precision--;
			}
		}
	}
	free(str);
	str = NULL;
	return (pointer->counter);
}

static void		print_chara(t_parse *p, t_s_to_fs *pointer, int neg)
{
	if (neg == 1)
		pointer->counter += ft_putchar_len('-');
	else if (p->f_plus == 1)
		pointer->counter += ft_putchar_len('+');
	else if (p->f_space == 1)
		pointer->counter += ft_putchar_len(' ');
}

void			print_f(t_parse *p, t_s_to_fs *pointer, t_for_f *ptr)
{
	if (ptr->neg == 1 || p->f_plus == 1 || p->f_space == 1)
		print_chara(p, pointer, ptr->neg);
	putf(p, pointer, ptr);
}

void			printf_no_min(t_parse *p, t_s_to_fs *pointer, t_for_f *ptr)
{
	if (p->f_zero == 0)
	{
		if (p->f_space == 1)
			print_chara(p, pointer, ptr->neg);
		if (p->f_zero == 1)
			ft_print_space(p, pointer, ptr->space, 2);
		else
			ft_print_space(p, pointer, ptr->space, 1);
		if (ptr->neg == 1 || p->f_plus == 1)
			print_chara(p, pointer, ptr->neg);
	}
	else
	{
		if (ptr->neg == 1 || p->f_plus == 1 || p->f_space == 1)
			print_chara(p, pointer, ptr->neg);
		ft_print_space(p, pointer, ptr->space, 1);
	}
	putf(p, pointer, ptr);
}
