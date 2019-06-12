/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:28:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/10 11:37:37 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*min_ll_int(unsigned long long nbr)
{
	char	*s1;
	char	*s2;

	if ((s1 = ft_utoa(nbr)) == NULL)
		return (NULL);
	if ((s2 = ft_strjoin("-", s1)) == NULL)
		return (NULL);
	ft_strdel(&s1);
	return (s2);
}

static int		checkflags_d(char *str, long long int nbr,
		t_data *data, t_buff *buff)
{
	int	ret;

	ret = 0;
	if (nbr == 0 && data->flags[precision] == 'z')
		str[0] = ' ';
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	if (data->flags[precision] != 'z'
			&& data->flags[precision] >= (int)ft_strlen(str))
	{
		ft_precision(str, data, buff);
		ret = 1;
	}
	else if (data->flags[width] > (int)ft_strlen(str))
	{
		ft_width(str, data, buff);
		ret = 1;
	}
	return (ret);
}

static void		sign_d(char *str, t_data *data, t_buff *buff)
{
	if (data->flags[sign] && str[0] != '-')
		ft_buffer('+', buff);
	else if (data->flags[space] && str[0] != '-')
		ft_buffer(' ', buff);
}

int				pf_d(va_list ap, t_data *data, t_buff *buff)
{
	long long int	nbr;
	char			*str;
	int				ret;

	nbr = ft_get_nbr(ap, data);
	if ((unsigned long long)nbr - 1 == 9223372036854775807)
		str = min_ll_int(nbr);
	else
	{
		if ((str = ft_itoa(nbr)) == NULL)
			return (-1);
	}
	ret = checkflags_d(str, nbr, data, buff);
	if (ret == 0)
	{
		sign_d(str, data, buff);
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
