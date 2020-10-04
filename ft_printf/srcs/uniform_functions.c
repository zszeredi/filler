/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/17 12:54:51 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_delete_double_array(char **str)
{
	int i;

	i = 0;
	while (i < 2)
		ft_strdel(&str[i++]);
	str = NULL;
	return (str);
}

void	ft_print_space(t_parse *p, t_s_to_fs *pointer, int space, int c)
{
	int i;

	i = 0;
	while (i++ < space)
	{
		if (p->f_zero == 1 || c == 2)
			ft_putchar_len('0');
		else
			ft_putchar_len(' ');
		pointer->counter++;
	}
}

void	dioux_width_print(t_parse *p, t_s_to_fs *pointer, t_for_pdioux *ptr)
{
	if (p->f_minus == 0)
	{
		ft_print_space(p, pointer, ptr->space, 0);
		pointer->counter += ft_putstr_len(ptr->str);
	}
	else
	{
		pointer->counter += ft_putstr_len(ptr->str);
		ft_print_space(p, pointer, ptr->space, 0);
	}
}
