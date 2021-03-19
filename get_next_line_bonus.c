/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:28:25 by jinspark          #+#    #+#             */
/*   Updated: 2021/03/20 02:30:20 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_next_line(char **line, char **backup, char **buf)
{
	const char	*temp = *backup;
	const char	*next = ft_strchr(*backup, '\n');

	if (next)
	{
		*line = ft_strndup(temp, next - temp);
		*backup = ft_strndup(next + 1, BUFFER_SIZE);
		free((void *)temp);
		free(*buf);
		return (1);
	}
	*line = (*backup) ? *backup : ft_strndup("", 1);
	*backup = NULL;
	free(*buf);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	ssize_t		count;
	char		*buf;
	char		*next;
	char		*temp;

	if (
		!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))) || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((!(next = ft_strchr(backup[fd], '\n')) &&
			(count = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		if (count == -1)
		{
			free(buf);
			return (-1);
		}
		buf[count] = '\0';
		temp = (backup[fd]) ? ft_strjoin(backup[fd], buf) :
								ft_strndup(buf, count);
		free(backup[fd]);
		backup[fd] = temp;
	}
	return (ft_next_line(line, &backup[fd], &buf));
}
