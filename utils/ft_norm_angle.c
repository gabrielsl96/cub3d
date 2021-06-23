/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:53:50 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/05/14 18:55:38 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	ft_norm_angle(double angle)
{
	if (angle < 0)
		return (angle += 360);
	else if (angle > 360)
		return (angle -= 360);
	else
		return (angle);
}
