/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:20:51 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/08/01 15:54:47 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	place_number(t_filler *datas, char score, int john_doe)
{
	int		i;
	int		j;

	i = 1;
	while (i + 1 < datas->map_height)
	{
		j = 1;
		while (j + 1 < datas->map_width)
		{
			if (datas->map[i][j] == john_doe)			
			{
				datas->map[i - 1][j] == '.' && i > 0 ? datas->map[i - 1][j] 
					= score : 0;
				datas->map[i - 1][j + 1] == '.' && i > 0 ?
					datas->map[i - 1][j + 1] = score : 0;
				datas->map[i + 1][j] == '.' ? datas->map[i + 1][j] = score : 0;
				datas->map[i + 1][j + 1] == '.' ?
					datas->map[i + 1][j + 1]= score : 0;
				datas->map[i][j + 1] == '.' ? datas->map[i][j + 1] = score : 0;
				datas->map[i - 1][j - 1] == '.' && i > 0 && j > 0 ?
					datas->map[i - 1][j - 1] = score : 0;
				datas->map[i][j - 1] == '.' && j > 0 ?
					datas->map[i][j - 1] = score : 0;
				datas->map[i + 1][j - 1] == '.' && j > 0 ?
					datas->map[i + 1][j - 1] = score : 0;
				datas->map[i - 1][j - 1] == '.' && i > 0 && j > 0 ?
					datas->map[i - 1][j - 1] = score : 0;
			}
			++j;
		}
		++i;
	}
	print_board(datas->map);
	STR("\n");
	return (1);
}

static int	track_is_full(t_filler *datas)
{
	int i;
	int j;

	i = 0;
	while (datas->map[i])
	{
		j = 0;
		while (datas->map[i][j])
		{
			if (datas->map[i][j] == '.')
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int			heat_map(t_filler *datas)
{
	char	score;

	score = 48;
	place_number(datas, score, datas->letter_enemy);
	while (!track_is_full(datas))
	{
		place_number(datas, score, (score - 1));
		score < 126 ? ++score : 0;
	}
	return (1);
}
