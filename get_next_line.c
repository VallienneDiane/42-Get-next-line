/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:45:53 by dvallien          #+#    #+#             */
/*   Updated: 2021/12/15 14:05:44 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_buf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_join_line(char *line, int fd, char *buf)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		line = ft_strjoin(line, buf);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
		if (ft_check_buf(buf) != -1)
		{
			ft_strcpy(buf, (buf + ft_check_buf(buf) + 1));
			return (line);
		}	
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (ret == -1)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	printf("BUF %s\n", buf);
	line = ft_join_line(line, fd, buf[fd]);
	if (line && ft_strlen(line))
		return (line);
	free(line);
	return (NULL);
}

int main(void)
{
	int fd;

	fd = open("texte.txt", O_RDONLY);
	printf("1 %s\n", get_next_line(fd));
	printf("2 %s", get_next_line(fd));
	return (0);
}