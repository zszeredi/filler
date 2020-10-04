/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdioux_enlarge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:32:53 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/13 10:15:59 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		pdioux_calc_zeros(t_parse *p, t_for_pdioux *ptr)
{
	int nb_zeros;

	if (ptr->c == 'o' && p->f_hash == 1 && ((p->precision <= ptr->str_l
					&& (p->width <= ptr->str_l || (p->width > ptr->str_l &&
							p->f_zero == 0))) || p->width == 0))
		nb_zeros = 1;
	else if (p->precision > -1)
		nb_zeros = p->precision - ptr->str_l;
	else
	{
		if (ptr->c == 'p' && ptr->u_n == 0)
			ptr->str_l = 3;
		else if ((ptr->c == 'p' && ptr->u_n > 0) || (ptr->c == 'x' &&
					p->f_hash == 1) || (ptr->c == 'X' && p->f_hash == 1))
			ptr->str_l = ptr->str_l + 2;
		nb_zeros = p->width - ptr->str_l;
	}
	return (nb_zeros);
}

int				calc_nb_zeros(t_parse *p, t_for_pdioux *ptr)
{
	int nb_zeros;

	if (ptr->c == 'd')
		nb_zeros = di_calc_zeros(p, ptr->str_l, ptr->di_n);
	else
		nb_zeros = pdioux_calc_zeros(p, ptr);
	return (nb_zeros);
}

char			*pdioux_enlarge_str(t_parse *p, t_for_pdioux *ptr)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((ptr->nb_zeros = calc_nb_zeros(p, ptr)) < 0)
		return (ptr->str);
	if (!(tmp = malloc(sizeof(char) * (ptr->nb_zeros + ptr->di_n + 1))))
		return (NULL);
	if (ptr->di_n == 1)
		tmp[i++] = '-';
	while (ptr->nb_zeros > 0)
	{
		tmp[i++] = '0';
		ptr->nb_zeros--;
	}
	tmp[i] = '\0';
	if (!(ptr->str = concentate_strings(tmp, ptr->str)))
		return (NULL);
	free(tmp);
	return (ptr->str);
}
