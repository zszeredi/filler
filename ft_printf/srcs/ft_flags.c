/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/26 16:12:13 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_parse	*flags_zero(t_parse *p)
{
	p->f_minus = 0;
	p->f_space = 0;
	p->f_hash = 0;
	p->f_zero = 0;
	p->f_plus = 0;
	return (p);
}

t_parse	*flags(char c, t_parse *p)
{
	if (c == 32)
		p->f_space = 1;
	else if (c == 35)
		p->f_hash = 1;
	else if (c == 43)
		p->f_plus = 1;
	else if (c == 45)
		p->f_minus = 1;
	else if (c == 48)
		p->f_zero = 1;
	return (p);
}
