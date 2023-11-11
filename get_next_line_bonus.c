/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:42:33 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/11 18:27:27 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_fd(int fd, char *line)
{
	char	*buffer;
	ssize_t	r;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	r = 1;
	while (find_endl(line) == -1 && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = 0;
		line = add_buffer(buffer, line);
	}
	free(buffer);
	return (line);
}

char	*get_line(char *s)
{
	char	*str;
	int		endl_pos;
	int		i;

	endl_pos = find_endl(s) + 1;
	str = malloc(endl_pos * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < endl_pos)
		str[i] = s[i];
	str[i] = 0;
	free(s);
	return (str);
}

char	*save_rest(char	*s)
{
	char	*str;
	size_t	endl_pos;
	int		i;

	endl_pos = find_endl(s) + 1;
	str = malloc((ft_strlen(s) - endl_pos + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s[endl_pos + ++i])
		str[i] = s[endl_pos + i];
	str[i] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[4096];
	char		*current_line;

	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	current_line = read_fd(fd, line[fd]);
	if (find_endl(current_line) == -1)
	{
		if (line[fd])
		{
			free(line[fd]);
			line[fd] = NULL;
			return (current_line);
		}
		return (NULL);
	}
	line[fd] = save_rest(current_line);
	current_line = get_line(current_line);
	return (current_line);
}
