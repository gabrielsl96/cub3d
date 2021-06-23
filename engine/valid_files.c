/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:22:13 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/01 23:15:28 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	message_error(char *msg_error)
{
	printf("Error\n%s\n", msg_error);
	exit(0);
	return ;
}

int	valid_ext(const char *str, char *extension)
{
	char	*aux;

	aux = ft_strrchr(str, '.');
	if (aux != NULL && ft_strlen(aux) == ft_strlen(extension)
		&& (ft_memcmp(aux, extension, ft_strlen(aux))) == 0)
		return (0);
	return (1);
}
