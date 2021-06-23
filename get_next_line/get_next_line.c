/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:40:36 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 21:07:39 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line(char **memo, char **line)
{
	char	*aux;
	size_t	i;

	i = 0;
	while ((*memo)[i] != '\0' && (*memo)[i] != '\n')
		i++;
	if ((*memo)[i] == '\n')
	{
		*line = ft_substr(*memo, 0, i);
		aux = ft_strdup(&(*memo)[i + 1]);
		free(*memo);
		*memo = aux;
	}
	else
	{
		*line = ft_strdup(*memo);
		free(*memo);
		*memo = NULL;
		return (0);
	}
	return (1);
}

int	ft_res(char **memo, char **line, int count)
{
	if (count < 0)
	{
		free(*memo);
		*memo = NULL;
		return (-1);
	}
	else
		return (ft_line(memo, line));
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*memo;
	int			count;
	char		*aux;

	if (fd < 0 || !line)
		return (-1);
	if (!memo)
	{
		memo = malloc(sizeof(memo) * 1);
		memo[0] = '\0';
	}
	count = read(fd, buffer, BUFFER_SIZE);
	while (count > 0)
	{
		buffer[count] = '\0';
		aux = ft_strjoin(memo, buffer);
		free(memo);
		memo = aux;
		if (ft_strchr(memo, '\n'))
			break ;
		count = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_res(&memo, line, count));
}
