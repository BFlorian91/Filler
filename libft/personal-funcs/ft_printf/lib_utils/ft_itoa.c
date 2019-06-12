/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:46:09 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 11:17:40 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

static int		ft_int_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_fill_str(char *str, int len, long long nbr, int neg)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = nbr % 10 + '0';
		i++;
		nbr = nbr / 10;
	}
	if (neg)
		str[i] = '-';
	return (str);
}

char			*ft_itoa(long long n)
{
	char		*str;
	int			n_len;
	int			neg;
	long long	nbr;

	neg = 0;
	nbr = n;
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	n_len = ft_int_len(nbr);
	if ((str = ft_strnew(n_len + neg)) == NULL)
		return (NULL);
	str = ft_fill_str(str, n_len, nbr, neg);
	str = ft_strrev(str);
	return (str);
}
