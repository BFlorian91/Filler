/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:49:24 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 11:32:36 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_get_float(va_list ap, t_data *data)
{
	long double	nbr;

	if (data->flags[L])
		nbr = va_arg(ap, long double);
	else if (data->flags[ll])
		nbr = (double)va_arg(ap, double);
	else
		nbr = (float)va_arg(ap, double);
	return (nbr);
}
