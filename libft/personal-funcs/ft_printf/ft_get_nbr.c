/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:47:22 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 11:32:54 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		ft_get_nbr(va_list ap, t_data *data)
{
	long long int	nbr;

	nbr = va_arg(ap, long long);
	if (data->flags[hh])
		nbr = (char)nbr;
	else if (data->flags[h])
		nbr = (short int)nbr;
	else if (data->flags[l])
		nbr = (long int)nbr;
	else if (data->flags[ll] == 0)
		nbr = (int)nbr;
	return (nbr);
}
