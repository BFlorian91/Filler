/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:24:12 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/10 11:36:54 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_b(va_list ap, t_data *data, t_buff *buff)
{
	long long	nbr;
	char		*str;

	nbr = ft_get_nbr(ap, data);
	if ((str = ft_itoa_base(nbr, 2)) == NULL)
		return (-1);
	if (data->flags[hashtag])
		data->flags[hashtag] = 0;
	if (data->flags[sign])
		data->flags[sign] = 0;
	if (data->flags[width] > (int)ft_strlen(str))
		ft_width(str, data, buff);
	else
	{
		if (data->flags[space])
			ft_buffer(' ', buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
