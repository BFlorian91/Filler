/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 17:34:05 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/09 21:04:36 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*b_neg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
		++i;
	}
	return (str);
}

char		*reverse_base(char *str, int neg, int base)
{
	char	tmp;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (neg && base == 10)
		j = 1;
	--i;
	while (i > j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		--i;
		++j;
	}
	if (base == 2 && neg)
		return (b_neg(str));
	return (str);
}
