/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:40:29 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/17 23:32:16 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**ft_arrchar(int width, int height)
{
	char	**arr;
	char	i;
	char	j;

	arr = malloc(sizeof(int **) * height + 1);
	while (i < height)
	{
		arr[i] = ft_calloc(width, sizeof(int));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
