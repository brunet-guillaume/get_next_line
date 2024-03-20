/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:47:38 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/13 14:28:04 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
char	*get_next_line(int fd);
void	*clean_exit(char *p_line);
int		get_endl_pos(char *prev_line);
void	*join_str(char *p_line, char *buf);

#endif
