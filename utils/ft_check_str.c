/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:46:32 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/01 23:41:42 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_check_str(char *str, char *params)
{
	int	i;
	int	j;
	int	compare;
	int	len;

	i = 0;
	compare = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		j = 0;
		while (params[j])
		{
			if (str[i] == params[j])
				compare++;
			j++;
		}
		i++;
	}
	if (len != compare)
		return (0);
	return (1);
}
