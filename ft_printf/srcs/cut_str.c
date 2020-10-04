/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2020/09/19 10:07:08 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		search(char charachter)
{
	if ((charachter == 'c' || charachter == 's' || charachter == 'p' ||
				charachter == 'd' || charachter == 'i' || charachter == 'o' ||
				charachter == 'u' || charachter == 'x' || charachter == 'X' ||
				charachter == 'f' || charachter == '%') && charachter != '\0')
		return (1);
	return (-1);
}

static char		*fs_len(t_s_to_fs *ptr, char *str)
{
	int n;

	n = 0;
	while ((search(str[ptr->position])) < 1)
	{
		if (ptr->position == ptr->string_len)
		{
			n = 1;
			break ;
		}
		ptr->fs_end++;
		ptr->position++;
	}
	if (n == 0)
	{
		if (!(ptr->fs = ft_strsub(str, ptr->fs_start, ptr->fs_end + 1)))
			return (NULL);
	}
	else
		ptr->fs = NULL;
	return (ptr->fs);
}

static void		printf_no_percent(t_s_to_fs *ptr, char *str)
{
	if (str[ptr->position] != '%')
	{
		ptr->counter++;
		write(1, &str[ptr->position], 1);
	}
}

t_s_to_fs		*cutting(t_s_to_fs *ptr, char *str)
{
	ptr->position = ptr->position - 1;
	while (++ptr->position < ptr->string_len)
	{
		if (str[ptr->position] != '%')
			printf_no_percent(ptr, str);
		if (str[ptr->position] == '%')
		{
			ptr->fs_end = 0;
			ptr->position++;
			ptr->fs_start = ptr->position;
			fs_len(ptr, str);
			return (ptr);
		}
	}
	return (ptr);
}
