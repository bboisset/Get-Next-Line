/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:54:02 by bboisset          #+#    #+#             */
/*   Updated: 2019/11/07 19:32:09 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		end_of_line(char *temp);
int		store_rest(char *temp, char **rest);
int		read_line(int const fd, char **line, char **rest);
int		get_next_line(int const fd, char **line);

int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
#endif
