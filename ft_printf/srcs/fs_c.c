/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/13 18:52:58 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_c_fs(t_parse *p, int chara, t_s_to_fs *pointer)
{
	char	c;
	int		space;

	c = (char)chara;
	if (p->f_zero == 1 && p->f_minus == 1)
		p->f_zero = 0;
	if (p->width == 0)
		pointer->counter += ft_putchar_len(c);
	else
	{
		space = p->width - 1;
		if (p->f_minus == 0)
		{
			ft_print_space(p, pointer, space, 1);
			pointer->counter += ft_putchar_len(c);
		}
		else
		{
			pointer->counter += ft_putchar_len(c);
			ft_print_space(p, pointer, space, 1);
		}
	}
	return (pointer->counter);
}
