/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:35:19 by yyan              #+#    #+#             */
/*   Updated: 2019/11/04 13:55:22 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	give_one_line(char **s, const int fd, char **line)
{
	int		i;
	char	*tp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int	give_all(char **s, const int fd, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	return (give_one_line(s, fd, line));
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*temporary;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		buff[ret] = '\0';
		temporary = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = temporary;
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	printf("The returned%d\n", **line);
	return (give_all(s, fd, line, ret));
}
