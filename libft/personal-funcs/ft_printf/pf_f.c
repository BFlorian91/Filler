/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:29:00 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 11:37:58 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					pf_f(va_list ap, t_data *data, t_buff *buff)
{
	long double	nbr;
	char		*str;

	nbr = ft_get_float(ap, data);
	if ((str = ft_ftoa(nbr, data)) == NULL)
		return (-1);
	if (data->flags[width] > (int)ft_strlen(str))
		ft_width(str, data, buff);
	else
	{
		if (data->flags[sign] && str[0] != '-')
			ft_buffer('+', buff);
		else if (data->flags[space] && str[0] != '-')
			ft_buffer(' ', buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
