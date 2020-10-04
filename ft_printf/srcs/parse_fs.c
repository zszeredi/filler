/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/13 19:27:11 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_parse	*pull_fs_apart(char *fs, t_parse *p)
{
	int		i;
	char	*str;

	p->fs_len = ft_strlen(fs);
	i = -1;
	while (fs[++i] == 32 || fs[i] == 35 || fs[i] == 43 || fs[i] == 45
			|| fs[i] == 48)
		p = flags(fs[i], p);
	str = ft_strsub(fs, i, p->fs_len);
	p = set_wp(p, str);
	p = length_modifier(p, str);
	free(str);
	return (p);
}

static t_parse	*save_star_values(t_parse *p, t_s_to_fs *ptr)
{
	va_list ac;
	int		i;
	int		num;

	i = 0;
	p->pos = ft_str_next_chr(ptr->fs, '.', '*');
	va_copy(ac, ptr->ap);
	if (!(p->array = malloc(sizeof(char *) * p->num_stars + 1)))
		return (NULL);
	num = va_arg(ac, int);
	if (num < 0 && p->pos == 1)
		p->f_minus = 1;
	p->array[i++] = num;
	if (p->num_stars == 2)
	{
		num = va_arg(ac, int);
		p->array[i++] = num;
	}
	p->array[i] = '\0';
	va_copy(ptr->ap, ac);
	va_end(ac);
	return (p);
}

int				formatted_string(t_s_to_fs *ptr)
{
	int		h;
	t_parse	*p;

	if (!(p = malloc(sizeof(t_parse))))
		return (-1);
	ptr->fs_len = ft_strlen(ptr->fs);
	p->num_stars = ft_strnchr(ptr->fs, '*');
	p = flags_zero(p);
	if (p->num_stars > 0)
		p = save_star_values(p, ptr);
	p = pull_fs_apart(ptr->fs, p);
	h = ptr->fs_len - 1;
	ptr->fs[h] == '%' ? ft_c_fs(p, 37, ptr) : 0;
	ptr->fs[h] == 'c' ? ft_c_fs(p, va_arg(ptr->ap, int), ptr) : 0;
	ptr->fs[h] == 's' ? ft_s_fs(p, va_arg(ptr->ap, char *), ptr) : 0;
	ptr->fs[h] == 'p' ? ft_p_fs(p, va_arg(ptr->ap, void *), ptr) : 0;
	ptr->fs[h] == 'i' || ptr->fs[h] == 'd' ? ft_di_fs(p, ptr) : 0;
	ptr->fs[h] == 'o' || ptr->fs[h] == 'u' || ptr->fs[h] == 'x' ||
		ptr->fs[h] == 'X' ? ft_oux_modifier(p, ptr, ptr->fs[h]) : 0;
	ptr->fs[h] == 'f' ? ft_f_fs(p, ptr) : 0;
	if (p->num_stars > 0)
		free(p->array);
	free(p);
	return (ptr->counter);
}
