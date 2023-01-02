/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:28:14 by hed-dyb           #+#    #+#             */
/*   Updated: 2022/11/27 11:09:32 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_after_newline(char *stock)
{
	char	*temp;
	int		a;
	int		i;

	i = 0;
	while (stock[i] != '\n')
	{
		if (stock[i] == '\0')
			return (free(stock), NULL);
		i++;
	}
	a = i + 1;
	while (stock[i] != '\0')
		i++;
	temp = ft_substr(stock, a, i - a);
	free(stock);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock[OPEN_MAX];
	char		*line;
	int			a;

	a = 1;
	if (fd > OPEN_MAX | fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(stock[fd], '\n') == 0 && a > 0)
	{
		a = read (fd, buffer, BUFFER_SIZE);
		if (a == -1)
			return (free (buffer), free (stock[fd]), (NULL));
		buffer[a] = '\0';
		stock[fd] = ft_strjoin(stock[fd], buffer);
	}
	free (buffer);
	line = ft_substr(stock[fd], 0, ft_line_len(stock[fd]) + 1);
	stock[fd] = get_after_newline(stock[fd]);
	return (line);
}
