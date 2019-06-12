/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:58:55 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 11:33:15 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		ft_get_unbr(va_list ap, t_data *data)
{
	unsigned long long int	nbr;

	nbr = va_arg(ap, unsigned long long int);
	if (data->flags[hh])
		nbr = (unsigned char)nbr;
	else if (data->flags[h])
		nbr = (short unsigned int)nbr;
	else if (data->flags[l])
		nbr = (long unsigned int)nbr;
	else if (data->flags[ll] == 0)
		nbr = (unsigned int)nbr;
	return (nbr);
}
