/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:54:28 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/11 18:23:42 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*add_buffer(char *buffer, char *line)
{
	char	*s;
	char	*ptr;

	s = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ptr = s;
	if (line)
		while (*line)
			*s++ = *line++;
	while (*buffer)
		*s++ = *buffer++;
	*s = 0;
	return (ptr);
}

int	find_endl(char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
