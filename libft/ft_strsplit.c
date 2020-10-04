/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:52:32 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 12:55:10 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nstrings(char const *s, char c)
{
	size_t	tmp;
	size_t	n;
	size_t	i;

	tmp = 0;
	n = 0;
	i = 1;
	if (c == 0)
		return (i);
	while (*s)
	{
		if (*s == c && tmp == 1)
			tmp = 0;
		if (*s != c && tmp == 0)
		{
			tmp = 1;
			n++;
		}
		s++;
	}
	return (n);
}

static size_t	lstring(char const *s, size_t start, char c)
{
	size_t	end;

	end = 0;
	while (s[start + end] && s[start + end] != c)
		end++;
	return (end);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	if (s == 0 || !(tab = malloc(sizeof(char *) * nstrings(s, c) + 1)))
		return (NULL);
	while (j < nstrings(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			l = lstring(s, i, c);
			if (!(tab[j] = ft_strsub(s, i, l)))
				return (NULL);
			i = i + l;
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
	free(tab);
}
