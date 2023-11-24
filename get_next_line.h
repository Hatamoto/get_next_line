/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:29:16 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/23 15:21:10 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# define FD_SIZE 4096;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_shift_left(char *buffer, int offset);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcpos(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*realloc_line(char *line);

#endif
