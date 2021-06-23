/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:12:44 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/20 20:27:26 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	count;
	int	signal;

	num = 0;
	count = 0;
	signal = 1;
	while ((nptr[count] >= 7 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			signal = -1;
		count++;
	}
	while (ft_isdigit(nptr[count]) == 1)
	{
		num = num * 10 + (nptr[count] - 48);
		count++;
	}
	return (num * signal);
}
