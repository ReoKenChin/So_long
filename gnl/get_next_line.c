/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:29:35 by mcherki           #+#    #+#             */
/*   Updated: 2022/01/07 17:48:35 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (ft_substr(str, 0, i + 1));
}

char	*get_rest(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] != '\n')
		i++;
	ptr = ft_substr(str, i + 1, ft_strlen(str) - i);
	free(str);
	return (ptr);
}

int	newline(char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			k;
	char		*line;
	static char	*rest;
	char		*buff;

	if (fd < 0)
		return (NULL);
	buff = malloc(2);
	if (!buff)
		return (NULL);
	if (newline(rest))
		return (line = get_line(rest), rest = get_rest(rest), free(buff), line);
    k = read(fd, buff, 1);
	if (k <= 0)
	{
		if (!rest)
			return (free(buff), NULL);
		if (!*rest)
			return (free(buff), free(rest), rest = NULL, NULL);
		line = ft_strdup(rest);
		return (free(rest), free(buff), rest = NULL, line);
	}
    buff[k] = '\0';
	return (rest = ft_strjoin(rest, buff), free(buff), get_next_line(fd));
}