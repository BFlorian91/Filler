/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/09 21:00:43 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			val(int nb)
{
	return (nb >= 0 && nb <= 9 ? nb + '0' : nb - 10 + 'a');
}

static int			size_after_convert(long long nb, int base)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		++len;
		nb /= base;
	}
	return (len);
}

static long long	convert_pos(long long nb, int *neg)
{
	if (nb < 0)
	{
		*neg = 1;
		nb *= -1;
	}
	return (nb);
}

char				*ft_itoa_base(long long nb, int base)
{
	char	*str;
	int		i;
	int		len;
	int		neg;

	i = 0;
	neg = 0;
	len = 0;
	if (base != 2)
		len = size_after_convert(nb, base);
	nb = convert_pos(nb, &neg);
	if (base == 2)
		len = size_after_convert(nb, base);
	if ((str = ft_strnew(len + neg)) == NULL)
		return (NULL);
	if (neg && base == 10)
		str[i++] = '-';
	if (base == 10 && neg)
		len++;
	while (i < len)
	{
		str[i++] = val(nb % base);
		nb /= base;
	}
	return (reverse_base(str, neg, base));
}
