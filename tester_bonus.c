/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:29:52 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/11 18:01:33 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int i = 0;
	int j = 0;
	int k = 0;
	char	*str;
	char	space[] = "                           ";
	char	stroke1[] = "--------------------------------------------------------------";
	char	stroke2[] = "-------------------------------";
	printf("%sBUFFER_SIZE : %d\n\n", space, BUFFER_SIZE);
	//fd = 0;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	
	str = get_next_line(fd1);
	i++;
	printf(" %s%d %s\n%s", num(i), i, stroke1,  str);
	free(str);
	
	str = get_next_line(fd2);
	j++;
	printf("%s %s%d %s\n%s", stroke2, num(j), j, stroke2,  str);
	free(str);

	str = get_next_line(fd2);
	j++;
	printf("%s %s%d %s\n%s", stroke2, num(j), j, stroke2,  str);
	free(str);
	
	str = get_next_line(fd3);
	k++;
	printf("%s %s%d \n%s", stroke1, num(k), k,  str);
	free(str);
	
	str = get_next_line(fd1);
	i++;
	printf(" %s%d %s\n%s", num(i), i, stroke1,  str);
	free(str);

	str = get_next_line(fd3);
	k++;
	printf("%s %s%d \n%s", stroke1, num(k), k,  str);
	free(str);
	
	str = get_next_line(fd2);
	j++;
	printf("%s %s%d %s\n%s", stroke2, num(j), j, stroke2,  str);
	free(str);
	
	str = get_next_line(fd1);
	i++;
	printf(" %s%d %s\n%s", num(i), i, stroke1,  str);
	free(str);
	
	str = get_next_line(fd1);
	i++;
	printf(" %s%d %s\n%s", num(i), i, stroke1,  str);
	free(str);
	
	str = get_next_line(fd1);
	i++;
	printf(" %s%d %s\n%s", num(i), i, stroke1,  str);
	free(str);
	
	str = get_next_line(fd3);
	k++;
	printf("%s %s%d \n%s", stroke1, num(k), k,  str);
	free(str);
	
	str = get_next_line(fd3);
	k++;
	printf("%s %s%d \n%s", stroke1, num(k), k,  str);
	free(str);
	
	str = get_next_line(fd2);
	j++;
	printf("%s %s%d %s\n%s", stroke2, num(j), j, stroke2,  str);
	free(str);
	
	str = get_next_line(fd2);
	j++;
	printf("%s %s%d %s\n%s", stroke2, num(j), j, stroke2,  str);
	free(str);
	
	str = get_next_line(fd3);
	k++;
	printf("%s %s%d \n%s", stroke1, num(k), k,  str);
	free(str);
	
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
