/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:50:59 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/10 17:58:09 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*upper_x(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}

static void	checkflags_x(char *str, unsigned long long nbr, t_data *data)
{
	if (data->flags[sign])
		data->flags[sign] = 0;
	if (nbr == 0 && data->flags[precision] == 'z')
	{
		if (data->flags[width] == 0)
			str[0] = '\0';
		else
			str[0] = ' ';
		data->flags[hashtag] = 0;
	}
	if (data->flags[hashtag])
		data->flags[width] -= 2;
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
}

static void	flagwidth_x(char *str, t_data *data, t_buff *buff)
{
	if (data->flags[hashtag] > 0 && data->flags[zero])
	{
		ft_buffer('0', buff);
		ft_buffer(data->conv, buff);
	}
	ft_width(str, data, buff);
}

int			pf_x(va_list ap, t_data *data, t_buff *buff)
{
	unsigned long long	nbr;
	char				*str;

	nbr = ft_get_unbr(ap, data);
	if ((str = ft_itoa_base(nbr, 16)) == NULL)
		return (-1);
	if (data->conv == 'X')
		str = upper_x(str);
	checkflags_x(str, nbr, data);
	if (data->flags[precision] != 'z'
			&& data->flags[precision] >= (int)ft_strlen(str))
		ft_precision(str, data, buff);
	else if (data->flags[width])
		flagwidth_x(str, data, buff);
	else
	{
		if (data->flags[hashtag] > 0 && nbr != 0)
		{
			ft_buffer('0', buff);
			ft_buffer(data->conv, buff);
		}
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
