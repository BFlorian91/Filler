/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:21:29 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/14 15:41:08 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		get_number(char *str, int *i)
{
	int		value;

	value = 0;
	if (str[*i] != ' ')
	{
		while (ft_isdigit(str[*i]))
		{
			value = value * 10 + str[*i] - 48;
			++(*i);
		}
	}
	return (value);
}

void	print_board(t_filler *datas)
{
	int		x;
	int 	y;

	y = 0;
	while (datas->map[y])
	{
		x = 0;
		while (datas->map[y][x])
		{
			ft_putchar_fd(datas->map[y][x], 2);
			++x;
		}
		ft_putchar_fd('\n', 2);
		++y;
	}
}
