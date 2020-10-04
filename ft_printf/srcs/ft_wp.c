/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/17 12:53:16 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		one_star(char *str, int *array, int position)
{
	if (ft_strchr(str, '*'))
		position = array[0];
	else
		position = ft_atoi_dot(str);
	return (position);
}

static t_parse	*two_stars(t_parse *p, char **str)
{
	int n;

	n = 0;
	if (ft_strchr(str[0], '*'))
	{
		p->width = p->array[0];
		n = 1;
	}
	else
		p->width = ft_atoi_dot(str[0]);
	if (n == 0 && ft_strchr(str[1], '*'))
		p->precision = p->array[0];
	else if (n == 1 && ft_strchr(str[1], '*'))
		p->precision = p->array[1];
	else
	{
		p->precision = ft_atoi_dot(str[1]);
		p->precision < 0 ? p->precision = -1 : 0;
	}
	return (p);
}

static t_parse	*wp_two_split(t_parse *p, char *fs)
{
	int		dot;
	char	*tmp[3];

	dot = ft_str_n_chr(fs, '.');
	tmp[0] = ft_strsub(fs, 0, dot + 1);
	tmp[1] = ft_strsub(fs, dot + 1, p->fs_len);
	tmp[2] = NULL;
	two_stars(p, tmp);
	ft_delete_double_array(tmp);
	return (p);
}

static t_parse	*wp_one_split(t_parse *p, char *fs, int i)
{
	char	*tmp;

	if (i == 1)
	{
		if (!(tmp = ft_strsub(fs, 1, p->fs_len)))
			return (NULL);
		if (i == 1)
			p->precision = one_star(tmp, p->array, p->precision);
		p->width = 0;
	}
	else
	{
		if (!(tmp = ft_strsub(fs, 0, p->fs_len)))
			return (NULL);
		p->width = one_star(tmp, p->array, p->width);
	}
	free(tmp);
	return (p);
}

t_parse			*set_wp(t_parse *p, char *fs)
{
	if (ft_strchr(fs, '.') != NULL)
	{
		if (fs[0] == '.')
			wp_one_split(p, fs, 1);
		else
			wp_two_split(p, fs);
		p->precision < 0 ? p->precision = -1 : 0;
	}
	else
	{
		wp_one_split(p, fs, 2);
		p->precision = -2;
	}
	if (p->width < 0)
	{
		p->width = p->width * -1;
		p->f_minus = 1;
	}
	return (p);
}
