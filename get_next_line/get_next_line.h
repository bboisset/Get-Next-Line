/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:58:26 by baptisteb         #+#    #+#             */
/*   Updated: 2019/10/25 12:03:53 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_read_stock
{
	char		*temp;
	size_t		index;
}				t_read_stock;

int				ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strndup(const char *s1, size_t max);
char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*read_line(int const fd, char *str, int *status);
int				get_next_line(int const fd, char **line);
#endif
