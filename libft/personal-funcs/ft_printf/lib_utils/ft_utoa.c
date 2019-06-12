/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 21:47:49 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/10 11:23:41 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

static int	u_len(unsigned long long nb)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		++len;
		nb /= 10;
	}
	return (len);
}

char		*ft_utoa(unsigned long long nb)
{
	char	*str;
	int		len;

	len = u_len(nb);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	--len;
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
