/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 14:26:59 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_parse	*length_modifier(t_parse *p, char *fs)
{
	const char *hh = "hh";
	const char *ll = "ll";

	p->ls = 0;
	ft_strstr(fs, hh) ? p->ls = 208 : 0;
	ft_strchr(fs, 'h') && p->ls == 0 ? p->ls = 104 : 0;
	ft_strstr(fs, ll) && p->ls == 0 ? p->ls = 216 : 0;
	ft_strchr(fs, 'l') && p->ls == 0 ? p->ls = 108 : 0;
	ft_strchr(fs, 'L') && p->ls == 0 ? p->ls = 76 : 0;
	return (p);
}
