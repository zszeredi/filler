/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/17 17:13:46 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		iterate(t_s_to_fs *ptr, char *str)
{
	while (++ptr->position < ptr->string_len)
	{
		ptr = cutting(ptr, str);
		if (ptr->fs != NULL)
			formatted_string(ptr);
		ft_strdel(&ptr->fs);
	}
}

int				ft_printf(const char *restrict s, ...)
{
	int			count;
	char		*str;
	t_s_to_fs	*ptr;

	if (!(ptr = malloc(sizeof(t_s_to_fs))))
		return (-1);
	va_start(ptr->ap, s);
	ptr->string_len = ft_strlen(s);
	str = (char *)s;
	ptr->position = -1;
	ptr->counter = 0;
	if ((ft_strchr(str, '%')) == NULL)
		ptr->counter += ft_putstr_len(str);
	else
		iterate(ptr, str);
	va_end(ptr->ap);
	str = NULL;
	count = ptr->counter;
	free(ptr);
	return (count);
}
