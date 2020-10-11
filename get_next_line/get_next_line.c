/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:57:38 by zszeredi          #+#    #+#             */
/*   Updated: 2020/10/09 17:48:27 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_split(const int fd, char **line, char **m)
{
	char	*tmp;
	int		i;

	i = 0;
	while (m[fd][i] != '\0' && m[fd][i] != '\n')
		i++;
	if (m[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(m[fd], 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(&m[fd][i + 1])))
			return (-1);
		ft_strdel(&m[fd]);
		m[fd] = tmp;
		if (m[fd][0] == '\0')
			ft_strdel(&m[fd]);
	}
	else
	{
		if (!(*line = ft_strdup(m[fd])))
			return (-1);
		ft_strdel(&m[fd]);
	}
	return (1);
}

static int	ft_errors(const int fd, char **line, char **m, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && m[fd] == NULL)
		return (0);
	else
		return (ft_split(fd, line, m));
}

int			get_next_line(const int fd, char **line)
{
	static char	*m[OPEN_MAX];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if ((fd < 0 && fd >= OPEN_MAX) || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (m[fd] == NULL)
		{
			if (!(m[fd] = ft_strdup(buf)))
				return (-1);
		}
		else
		{
			if (!(tmp = ft_strjoin(m[fd], buf)))
				return (-1);
			free(m[fd]);
			m[fd] = tmp;
		}
	}	
	return (ft_errors(fd, line, m, ret));
}
