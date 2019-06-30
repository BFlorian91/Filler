/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:06:52 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/30 15:07:00 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		can_place(t_filler *datas, int x, int y)
{
	int 	i;
	int 	j;
	int		my_player_char;	

	j = 0;
	my_player_char = 0;
	while (j + y < datas->map_height && j < datas->piece_height)
	{
		i = 0;
		while (i + x < datas->map_width && i < datas->piece_width)
		{
			if (datas->piece[j][i] == '*' && datas->map[j + y][i + x] == datas->letter_me)
				++my_player_char;
			if (datas->piece[j][i] == '*' && datas->map[j + y][i + x] == datas->letter_enemy)
				return (0);
			++i;
		}
		++j;
	}
	return (my_player_char == 1 ? 1 : 0);
}

int		place(t_filler *datas)
{
	int x;
	int y;

	y = 0;
	while (y + datas->piece_height <= datas->map_height)
	{
		x = 0;
		while (x + datas->piece_width <= datas->map_width)
		{
			if (can_place(datas, x, y))
			{
				ft_putstr(ft_itoa(y));
				ft_putchar(' ');
				ft_putstr(ft_itoa(x));
				ft_putchar('\n');
				return (1);
			}
			++x;
		}
		++y;
	}
	ft_putchar('0');
	ft_putchar(' ');
	ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
