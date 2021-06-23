/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:20:47 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/03 22:31:15 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_freearr(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}