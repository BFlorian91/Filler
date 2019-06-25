/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:35:39 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/25 23:45:48 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		check_first_pieces(t_filler *datas, int *x, int *y)
{
	while (datas->map[*y] && datas->map[*y][*x] != datas->letter_me)
	{
		++(*x);
		if (datas->map[*y][*x] == '\0')
		{
			*x = 0;
			++(*y);
		}
	}
	return (1);
}

int		can_place(t_filler *datas, int x, int y)
{
	unsigned int i;
	unsigned int j;
	bool me;

	j = 0;
	me = 0;
	while (j < datas->piece_width)
	{
		i = 0;
		while (i < datas->piece_height)
		{
			if (datas->piece[j][i] == '*' && datas->map[j + y][i + x] == datas->letter_enemy)
				return (0);
			if (datas->piece[j][i] == '*' && datas->map[j + y][i + x] == datas->letter_me)
				++me;
			++i;
		}
		++j;
	}
	if (me == 1)
		return (1);
	return (0);
}

int		place(t_filler *datas)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (y < datas->map_width)
	{
		y = 0;
		while (x < datas->map_height)
		{
			if (can_place(datas, x, y))
			{
				ft_putchar(x + 48);
				ft_putchar(' ');
				ft_putchar(y + 48);
				return (1);
			}
			++y;
		}
		++x;
	}
	return (0);
}
