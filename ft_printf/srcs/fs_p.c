/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 10:30:48 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_p_fs(t_parse *p, void *pt, t_s_to_fs *pointer)
{
	t_for_pdioux *ptr;

	if (!(ptr = malloc(sizeof(t_for_pdioux))))
		return (-1);
	ptr->c = 'p';
	ptr->di_n = 0;
	ptr->base = 16;
	ptr->u_n = (uintmax_t)pt;
	ptr->s_n = 1;
	pointer->counter = pdioux_main(p, pointer, ptr);
	return (pointer->counter);
}
