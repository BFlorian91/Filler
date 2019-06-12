/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:38:41 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/10 11:38:35 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_p(va_list ap, t_data *data, t_buff *buff)
{
	long long	nbr;
	char		*str;

	(void)data;
	nbr = va_arg(ap, long long);
	if ((str = ft_itoa_base(nbr, 16)) == NULL)
		return (-1);
	if (data->flags[sign])
		data->flags[sign] = 0;
	if (data->flags[width])
		data->flags[width] -= 2;
	if (data->flags[width] > (int)ft_strlen(str))
	{
		if (data->flags[zero])
			ft_str_to_buff("0x", buff);
		ft_width(str, data, buff);
	}
	else
	{
		ft_str_to_buff("0x", buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
