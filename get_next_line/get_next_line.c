/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:33:20 by baptisteb         #+#    #+#             */
/*   Updated: 2019/10/29 17:10:23 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_line_end(char *temp, size_t index)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (temp)
		while (temp[i])
		{
			if (temp[i++] == '\n')
				j++;
		}
	if (j == index)
		return (0);
	else
		return (1);
}

char	*read_temp(char *temp, size_t index)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	char	dst;

	i = 0;
	j = 0;
	str_len = 0;
	if (temp)
		while (temp[i])
		{
			str_len++;
			if (temp[i++] == '\n' || (temp[i] == '\0' && temp[i - 1] != '\n'))
			{
				if (temp[i] == '\0' && temp[i - 1] != '\n')
					j++;
				if (index-- == 0)
					return (ft_substr(temp, i - str_len, str_len - 1 + j));
				str_len = 0;
			}
		}
	return (ft_substr("", 0, 1));
}

char	*read_line(int const fd, char *str, int *status)
{
	char					*buffer;
	size_t					res;
	static	t_read_stock	read_line = {.temp = 0, .index = 0};

	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (NULL);
	while (is_line_end(read_line.temp, read_line.index) == 0 &&
			(res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		if (!(read_line.temp = ft_strjoin(read_line.temp, buffer)))
			return (NULL);
	}
	free(buffer);
	str = read_temp(read_line.temp, read_line.index);
	if (res <= 0 && is_line_end(read_line.temp, read_line.index) == 0)
	{
		*status = 0;
		free(read_line.temp);
		read_line.temp = NULL;
		read_line.index = 0;
	}
	else
		read_line.index++;
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	size_t	i;
	int		status;
	char	*str;

	str = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	i = 0;
	status = 1;
	if (!(*line = read_line(fd, str, &status)))
		return (-1);
	if (status == 0)
		return (0);
	return (1);
}
