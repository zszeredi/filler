/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concentate_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/26 16:50:10 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*concentate_strings(char *tmp, char *main_s)
{
	char *save;

	if (!(save = ft_strjoin(tmp, main_s)))
		return (NULL);
	free(main_s);
	if (!(main_s = ft_strdup(save)))
		return (NULL);
	free(save);
	return (main_s);
}
