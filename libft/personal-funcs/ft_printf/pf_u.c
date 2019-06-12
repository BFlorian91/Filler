/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:22:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/10 11:39:41 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	checkflags_u(t_data *data, t_buff *buff)
{
	if (data->flags[sign])
		ft_buffer('+', buff);
	else if (data->flags[space])
		ft_buffer(' ', buff);
}

int			pf_u(va_list ap, t_data *data, t_buff *buff)
{
	unsigned long long int	nbr;
	char					*str;

	nbr = ft_get_unbr(ap, data);
	if ((str = ft_itoa(nbr)) == NULL)
		return (-1);
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	if (data->flags[precision] != 'z'
			&& data->flags[precision] >= (int)ft_strlen(str))
		ft_precision(str, data, buff);
	else if (data->flags[width])
		ft_width(str, data, buff);
	else
	{
		checkflags_u(data, buff);
		if (data->flags[precision] == 'z' && nbr == 0)
		{
			ft_strdel(&str);
			return (0);
		}
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
