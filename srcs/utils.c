/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:21:29 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/13 15:46:05 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		get_number(char *str)
{
	int		value;
	int		i;

	value = 0;
	i = 0;
	if (str[i] != ' ')
	{
		while (ft_isdigit(str[i]))
		{
			value = value * 10 + str[i] - 48;
			++i;
		}
	}
	return (value);
}
