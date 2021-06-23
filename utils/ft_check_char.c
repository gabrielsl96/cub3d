/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:46:32 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/04/23 17:03:56 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_check_char(char c, char *params)
{
	int	i;

	i = 0;
	while (params[i])
	{
		if (params[i] == c)
			return (1);
		i++;
	}
	return (0);
}
