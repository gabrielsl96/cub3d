/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr_to_arrint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:21:28 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/01 23:21:15 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	*arrstr_to_arrint(char **arr)
{
	int	*arr_num;
	int	len;
	int	i;
	int	aux;

	len = ft_arrlen(arr);
	i = 0;
	if (!len)
		return (NULL);
	arr_num = malloc(sizeof(int) * (len + 1));
	while (i < len)
	{
		arr_num[i] = ft_atoi(arr[i]);
		i++;
	}
	arr_num[i] = 0;
	return (arr_num);
}
