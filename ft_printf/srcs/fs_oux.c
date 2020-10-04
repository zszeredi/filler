/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oux_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/08/18 09:35:11 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_oux_modifier(t_parse *p, t_s_to_fs *pointer, char c)
{
	t_for_pdioux *ptr;

	if (!(ptr = malloc(sizeof(t_for_pdioux))))
		return (-1);
	ptr->di_n = 0;
	if (p->ls == 104)
		ptr->u_n = (unsigned short)va_arg(pointer->ap, unsigned int);
	else if (p->ls == 208)
		ptr->u_n = (unsigned char)va_arg(pointer->ap, unsigned int);
	else if (p->ls == 108)
		ptr->u_n = (unsigned long)va_arg(pointer->ap, unsigned long);
	else if (p->ls == 216)
		ptr->u_n = (unsigned long long)va_arg(pointer->ap, unsigned long long);
	else
		ptr->u_n = (unsigned int)va_arg(pointer->ap, unsigned int);
	c == 'o' ? ptr->c = 'o' : 0;
	c == 'o' ? ptr->base = 8 : 0;
	c == 'u' ? ptr->c = 'u' : 0;
	c == 'u' ? ptr->base = 10 : 0;
	c == 'X' ? ptr->c = 'X' : 0;
	c == 'x' ? ptr->c = 'x' : 0;
	c == 'X' || c == 'x' ? ptr->base = 16 : 0;
	ptr->s_n = 1;
	pointer->counter = pdioux_main(p, pointer, ptr);
	return (pointer->counter);
}
