/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:29:52 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/11 18:33:02 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

char	*num(int i)
{
	if (i < 10)
		return ("000");
	if (i < 100)
		return ("00");
	if (i < 1000)
		return ("0");
	return ("");
}

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 1)
		return (0);
	int	fd;
	int i = 0;
	char	*str;
	char	space[] = "                           ";
	char	stroke[] = "-------------------------------";
	printf("%sBUFFER_SIZE : %d\n\n", space, BUFFER_SIZE);
	//fd = 0;
	if (ac == 2)
	{
		if (av[1][0] == '1')
			fd = open("test.txt", O_RDONLY);
		else if (av[1][0] == '2')
			fd = open("test2.txt", O_RDONLY);
		else if (av[1][0] == '3')
			fd = open("test3.txt", O_RDONLY);
		else
			return (0);
	}
	else
		fd = 0;
	str = get_next_line(fd);
	while (str)
	{
		i++;
		if (str)
			printf("%s %s%d %s\n%s", stroke, num(i), i, stroke,  str);
		free(str);
		str = get_next_line((fd));
	}
	close(fd);
	return (0);
}
