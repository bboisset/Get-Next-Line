/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:59:54 by baptisteb         #+#    #+#             */
/*   Updated: 2019/10/31 17:20:17 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	if (s1)
		while (s1[j] != '\0')
			new_str[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j] != '\0')
			new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str2;
	size_t	i;
	size_t	s_len;

	s_len = (size_t)ft_strlen(s);
	start = (start > s_len ? s_len : start);
	len = (start + len > s_len) ? s_len - start : len;
	str2 = malloc((len + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		str2[i] = s[start + i];
		++i;
	}
	str2[i] = '\0';
	return (str2);
}
