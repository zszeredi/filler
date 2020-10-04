/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdioux_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:36:47 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 11:03:21 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				pdioux_no_print(t_parse *p, t_for_pdioux *ptr)
{
	if (ptr->c == 'd' && ptr->s_n == 0 && p->precision == 0 && p->width == 0 &&
			p->f_space == 0 && p->f_plus == 0)
	{
		free(ptr->str);
		return (1);
	}
	else if (ptr->c == 'o' && ptr->u_n == 0 && p->precision == 0 &&
			p->width == 0
			&& p->f_hash == 0)
	{
		free(ptr->str);
		return (1);
	}
	else if ((ptr->c == 'u' || ptr->c == 'x' || ptr->c == 'X') && ptr->u_n == 0
			&& p->precision == 0 && p->width == 0)
	{
		free(ptr->str);
		return (1);
	}
	return (0);
}

t_parse			*pdioux_null_flags(t_parse *p, t_for_pdioux *ptr)
{
	if (p->f_zero == 1 && (p->f_minus == 1 || p->precision > -1))
		p->f_zero = 0;
	if (ptr->c == 'o')
	{
		if ((p->f_zero == 1 && p->width > ptr->str_l) ||
				p->precision > ptr->str_l)
			p->f_hash = 0;
	}
	if (ptr->c == 'd')
	{
		if ((p->f_plus == 1 || ptr->s_n < 0) && p->f_space == 1)
			p->f_space = 0;
		if (ptr->s_n < 0)
			p->f_plus = 0;
	}
	if ((ptr->c == 'x' || ptr->c == 'X') && ptr->u_n == 0)
		p->f_hash = 0;
	return (p);
}

t_for_pdioux	*pdioux_modif_str(t_parse *p, t_for_pdioux *ptr)
{
	if (ptr->c == 'd' && (p->f_plus == 1 || p->f_space == 1 || p->precision >=
				ptr->str_l || (p->f_zero == 1 && p->width > ptr->str_l)))
		ptr = di_enlarge_str(p, ptr);
	else if ((p->precision >= ptr->str_l && p->precision != 1) || p->f_zero
			== 1 || (p->f_hash == 1 && ptr->c == 'o' && ptr->u_n > 0))
		ptr->str = pdioux_enlarge_str(p, ptr);
	(ptr->c == 'x' && p->f_hash == 1) || ptr->c == 'p' ? ptr->str =
		concentate_strings("0x", ptr->str) : 0;
	ptr->c == 'X' && p->f_hash == 1 ? ptr->str =
		concentate_strings("0X", ptr->str) : 0;
	ptr->str_l = ft_strlen(ptr->str);
	return (ptr);
}

int				pdioux_main(t_parse *p, t_s_to_fs *pointer, t_for_pdioux *ptr)
{
	if ((ptr->str = pdioux_str_create(p, ptr)) == NULL)
	{
		pointer->counter = ft_putstr_len("error");
		free(ptr);
		return (pointer->counter);
	}
	ptr->str_l = ft_strlen(ptr->str);
	p = pdioux_null_flags(p, ptr);
	if ((pdioux_no_print(p, ptr)) == 1)
	{
		free(ptr);
		return (pointer->counter);
	}
	ptr = pdioux_modif_str(p, ptr);
	if (p->width > ptr->str_l)
	{
		ptr->space = p->width - ptr->str_l;
		dioux_width_print(p, pointer, ptr);
	}
	else
		pointer->counter += ft_putstr_len(ptr->str);
	free(ptr->str);
	free(ptr);
	return (pointer->counter);
}
