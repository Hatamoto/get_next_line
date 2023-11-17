/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:29:16 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/17 18:41:42 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 64
#endif

char	*get_next_line(int fd);
int		check_line_end(char *buf);

#endif
