/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:53:06 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/27 17:43:15 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_check(char *str);
char	*get_next_line(int fd);
int		ft2_strlen(char *str);
char	*freenquit(char *free1, char *free2, char *rtn);
char	*ft2_strdup(char *str);
char	*strmcat(char *s1, char *s2);

#endif
