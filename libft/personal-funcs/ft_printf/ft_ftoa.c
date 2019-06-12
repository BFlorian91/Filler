/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:42:49 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 11:32:03 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len_bfr_coma(long double nbr)
{
	int	len;

	len = 0;
	while (nbr >= 1)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static int	get_prec(t_data *data)
{
	int	prec;

	prec = data->flags[precision];
	if (prec == 0)
		prec = 6;
	if (prec == 'z')
		prec = 0;
	return (prec);
}

static void	str_bfr_coma(long double nbr, char *str, int len, int neg)
{
	int	i;

	i = len - 1;
	if (neg)
		str[0] = '-';
	if (nbr == 0)
		str[0] = '0';
	while (nbr >= 1)
	{
		str[i--] = (int)nbr % 10 + '0';
		nbr /= 10;
	}
}

static char	*ft_ftoa_core(long double nbr, char *str, int prec, int i)
{
	while (prec > 0)
	{
		nbr *= 10;
		str[i++] = (int)nbr % 10 + '0';
		prec--;
	}
	return (str);
}

char		*ft_ftoa(long double nbr, t_data *data)
{
	char	*str;
	int		len_bfr_coma;
	int		prec;
	int		i;
	int		neg;

	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	len_bfr_coma = get_len_bfr_coma(nbr) + neg;
	prec = get_prec(data);
	if ((str = ft_strnew(len_bfr_coma + prec + 1)) == NULL)
		return (NULL);
	str_bfr_coma(nbr, str, len_bfr_coma, neg);
	i = len_bfr_coma;
	if (nbr == 0)
		i++;
	if (prec > 0)
		str[i++] = '.';
	return (ft_ftoa_core(nbr, str, prec, i));
}
