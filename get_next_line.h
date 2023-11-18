/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:29:16 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/18 18:20:01 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

char	*get_next_line(int fd);
int		check_line_end(char *buf);
char	*realloc_line(char *line);

size_t  ft_strlen(const char *str);

#endif
