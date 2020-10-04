/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 10:50:26 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		space_calc(t_parse *p, int len)
{
	int space;

	if (p->precision < len && p->precision >= 0)
		space = p->width - p->precision;
	else
		space = p->width - len;
	return (space);
}

static void		ft_s_fs_two(t_parse *p, t_s_to_fs *pointer, char *s, int len)
{
	int space;

	space = space_calc(p, len);
	if (p->f_minus == 0)
	{
		ft_print_space(p, pointer, space, 1);
		if (p->precision >= 0 && p->precision < len)
			pointer->counter += ft_putnstr(s, p->precision);
		else
			pointer->counter += ft_putstr_len(s);
	}
	else if (p->f_minus == 1)
	{
		if (p->precision >= 0 && p->precision < len)
			pointer->counter += ft_putnstr(s, p->precision);
		else
			pointer->counter += ft_putstr_len(s);
		p->f_zero = 0;
		ft_print_space(p, pointer, space, 1);
	}
}

char			*s_str_create(t_parse *p, char *string)
{
	char *s;

	if (string == NULL && p->precision != 0)
	{
		if (!(s = ft_strdup("(null)")))
			return (NULL);
	}
	else if (p->precision == 0)
	{
		if (!(s = ft_strdup("")))
			return (NULL);
	}
	else
	{
		if (!(s = ft_strdup(string)))
			return (NULL);
	}
	return (s);
}

int				ft_s_fs(t_parse *p, char *string, t_s_to_fs *pointer)
{
	int		len;
	char	*s;

	s = s_str_create(p, string);
	len = ft_strlen(s);
	ft_s_fs_two(p, pointer, s, len);
	free(s);
	return (pointer->counter);
}
