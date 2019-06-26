/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:35:39 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/26 19:33:49 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		can_place(t_filler *datas, int x, int y)
{
	int i;
	int j;
	bool my_player_char;

	j = 0;
	my_player_char = 0;
	while (j < datas->piece_width)
	{
		i = 0;
		while (i < datas->piece_height)
		{
			if (datas->piece[j][i] == '*' && datas->map[j + y][i + x] == datas->letter_me)
				++my_player_char;
			if (datas->piece[j][i] == '*' && datas->map[j + y][i + x] == datas->letter_enemy)
				return (0);
			++i;
		}
		++j;
	}
	if (my_player_char != 1)
		return (0);
	return (1);
}

int		place(t_filler *datas)
{
	int x;
	int y;

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
