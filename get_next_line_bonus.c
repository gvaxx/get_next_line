/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 23:09:29 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/18 12:35:30 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	push(char **buf, char **line)
{
	char *n;
	char *temp;

	if ((n = ft_strchr(*buf, '\n')))
	{
		*line = ft_strnjoin(*line, *buf, n - *buf);
		temp = *buf;
		*buf = ft_strdup(n + 1);
		free(temp);
		temp = 0;
		if (!(*line) || !(*buf))
			return (-1);
		return (1);
	}
	*line = ft_strnjoin(*line, *buf, BUFFER_SIZE);
	return (0);
}

int	free_all(char **buf, char **line, int flag)
{
	if (flag)
	{
		free(*buf);
		free(*line);
		*line = 0;
		*buf = 0;
		return (-1);
	}
	free(*buf);
	*buf = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf[10000];
	char		temp[1];
	int			n;
	int			p;

	if (BUFFER_SIZE < 1 || fd < 0 || (read(fd, temp, 0) < 0) || !line ||
	!(*line = ft_strdup("")))
		return (-1);
	if (buf[fd])
		if ((p = push(&buf[fd], line)))
			return (p == 1 ? 1 : free_all(&buf[fd], line, 1));
	free(buf[fd]);
	if (!(buf[fd] = malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (-1);
	while (0 < (n = read(fd, buf[fd], BUFFER_SIZE)))
	{
		buf[fd][n] = '\0';
		if ((p = push(&buf[fd], line)))
			return (p == 1 ? 1 : free_all(&buf[fd], line, 1));
	}
	return (n == 0 ? free_all(&buf[fd], line, 0) : free_all(&buf[fd], line, 1));
}
