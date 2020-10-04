/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:36:40 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/17 12:54:17 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*di_add_c_before(t_parse *p, char *str)
{
	char tmp[2];

	if (p->f_plus == 1)
		tmp[0] = '+';
	else
		tmp[0] = ' ';
	tmp[1] = '\0';
	if (!(str = concentate_strings(tmp, str)))
		return (NULL);
	return (str);
}

int				di_calc_zeros(t_parse *p, int str_l, int neg)
{
	int nb_zeros;

	if (p->precision > -1)
		nb_zeros = p->precision - str_l;
	else
	{
		if (neg == 1)
			str_l = str_l + 1;
		if (p->width == 0)
			nb_zeros = 0;
		else if (p->f_plus == 1 || p->f_space == 1)
			nb_zeros = p->width - str_l - 1;
		else
			nb_zeros = p->width - str_l;
	}
	return (nb_zeros);
}

t_for_pdioux	*di_enlarge_str(t_parse *p, t_for_pdioux *ptr)
{
	if (p->precision >= ptr->str_l || p->f_zero == 1)
	{
		if (ptr->s_n < 0)
		{
			free(ptr->str);
			ptr->s_n = ptr->s_n * -1;
			ptr->str = pdioux_str_create(p, ptr);
			ptr->str_l = ft_strlen(ptr->str);
			ptr->di_n = 1;
			ptr->str = pdioux_enlarge_str(p, ptr);
		}
		else
			ptr->str = pdioux_enlarge_str(p, ptr);
	}
	if ((p->f_plus == 1 && ptr->s_n >= 0) || p->f_space == 1)
		ptr->str = di_add_c_before(p, ptr->str);
	ptr->str_l = ft_strlen(ptr->str);
	return (ptr);
}

int				ft_di_fs(t_parse *p, t_s_to_fs *pointer)
{
	t_for_pdioux *ptr;

	if (!(ptr = malloc(sizeof(t_for_pdioux))))
		return (-1);
	ptr->c = 'd';
	if (p->ls == 208)
		ptr->s_n = (signed char)va_arg(pointer->ap, int);
	else if (p->ls == 104)
		ptr->s_n = (short)va_arg(pointer->ap, int);
	else if (p->ls == 108)
		ptr->s_n = (long)va_arg(pointer->ap, long);
	else if (p->ls == 216)
		ptr->s_n = (long long)va_arg(pointer->ap, long long int);
	else
		ptr->s_n = (int)va_arg(pointer->ap, int);
	ptr->u_n = 1;
	ptr->base = 10;
	ptr->di_n = 0;
	pointer->counter = pdioux_main(p, pointer, ptr);
	return (pointer->counter);
}
