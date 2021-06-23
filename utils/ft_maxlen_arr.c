/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxlen_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:02:27 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/17 02:11:00 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_maxlen_arr(char **arr)
{
	int	i;
	int	len;
	int	len_max;

	len = 0;
	len_max = 0;
	i = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > len_max)
			len_max = len;
		i++;
	}
	return (len_max);
}
