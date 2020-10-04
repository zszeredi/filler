/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdioux_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:21:56 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/13 19:27:04 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*diu_str_ll_create(t_for_pdioux *ptr)
{
	if (ptr->c == 'd')
	{
		if (!(ptr->str = ft_ll_itoa(ptr->s_n)))
			return (NULL);
	}
	else if (ptr->c == 'u')
	{
		if (!(ptr->str = ft_ll_uitoa(ptr->u_n)))
			return (NULL);
	}
	return (ptr->str);
}

static char		*pdioux_str_ll_create(t_for_pdioux *ptr)
{
	if (ptr->c == 'd' || ptr->c == 'u')
		ptr->str = diu_str_ll_create(ptr);
	else if (ptr->c == 'X')
	{
		if (!(ptr->str = ft_ll_uitoa_base(ptr->u_n, ptr->base, 1)))
			return (NULL);
	}
	else
	{
		if (!(ptr->str = ft_ll_uitoa_base(ptr->u_n, ptr->base, 0)))
			return (NULL);
	}
	return (ptr->str);
}

static char		*diu_str_create(t_for_pdioux *ptr)
{
	if (ptr->c == 'd')
	{
		if (!(ptr->str = ft_itoa(ptr->s_n)))
			return (NULL);
	}
	else if (ptr->c == 'u')
	{
		if (!(ptr->str = ft_uitoa(ptr->u_n)))
			return (NULL);
	}
	return (ptr->str);
}

char			*pdioux_str_create(t_parse *p, t_for_pdioux *ptr)
{
	if (p->precision == 0 && (ptr->s_n == 0 || ptr->u_n == 0))
	{
		if (!(ptr->str = ft_strnew(1)))
			return (NULL);
	}
	else if (p->ls == 216 || p->ls == 108)
		ptr->str = pdioux_str_ll_create(ptr);
	else if (ptr->c == 'd' || ptr->c == 'u')
		ptr->str = diu_str_create(ptr);
	else if (ptr->c == 'p')
	{
		if (!(ptr->str = ft_ll_uitoa_base(ptr->u_n, ptr->base, 0)))
			return (NULL);
	}
	else if (ptr->c == 'X')
	{
		if (!(ptr->str = ft_uitoa_base(ptr->u_n, ptr->base, 1)))
			return (NULL);
	}
	else
	{
		if (!(ptr->str = ft_uitoa_base(ptr->u_n, ptr->base, 0)))
			return (NULL);
	}
	return (ptr->str);
}
