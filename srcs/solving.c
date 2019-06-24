/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:35:39 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/24 20:40:13 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		check_older_pieces(t_filler *datas, int *x, int *y)
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
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (datas->map[y][x] != datas->letter_me)
	{
		++x;
		if (datas->map[y][x] == '\0')
		{
			x = 0;
			++y;
		}
	}
	while (datas->piece[k][l])
	{
		while (y + l < datas->map_width && l < datas->piece_width)
		{
			++l;
			if (datas->piece[k][l] == '*')
				++y;
		}
		if ((l == datas->piece_width || datas->piece[k][l] == '*')
				&& i < datas->map_height && k < datas->piece_height)
		{
			l = 0;
			++k;
			x += k;
		}
	}
	return (1);
}

int		place(t_filler *datas, int x, int y)
{
	while (y < datas->map_width)
	{
		y = 0;
		while (x < datas->map_height)
		{
			check_older_pieces(datas, &x, &y);
			if (datas->map[y][x] == datas->letter_me)
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
