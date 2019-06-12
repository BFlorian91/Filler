/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:07:05 by sgury             #+#    #+#             */
/*   Updated: 2019/05/29 11:42:46 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

int	ft_atoi(const char *str)
{
	unsigned int	nbr;
	int				neg;

	nbr = 0;
	neg = 1;
	while (*str == '\f' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str++ - '0';
		if (neg == -1 && nbr > 2147483648)
			return (0);
	}
	return (nbr * neg);
}
