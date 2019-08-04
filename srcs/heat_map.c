/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:20:51 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/08/04 18:53:09 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	place_number(t_filler *datas, char score, char previous)
{
	int		i;
	int		j;

	i = 1;
	while (i + 1 < datas->map_height)
	{
		j = 1;
		while (j + 1 < datas->map_width)
		{
			if (datas->map[i][j] == previous)
			{
				if (datas->map[UP][j] == '.')
					datas->map[UP][j] = score;
				if (datas->map[UP][RIGHT] == '.')
					datas->map[UP][RIGHT] = score;
				if (datas->map[UP][LEFT] == '.')
					datas->map[UP][LEFT] = score;
				if (datas->map[DOWN][j] == '.')
					datas->map[DOWN][j] = score;
				if (datas->map[DOWN][RIGHT] == '.')
					datas->map[DOWN][RIGHT]= score;
				if (datas->map[DOWN][LEFT] == '.')
					datas->map[DOWN][LEFT] = score;
				if (datas->map[i][RIGHT] == '.')
					datas->map[i][RIGHT] = score;
				if (datas->map[i][LEFT] == '.')
					datas->map[i][LEFT] = score;
			}
			++j;
		}
		++i;
	}
/*print_board(datas->map);*/
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
		if (score < 126)
			++score;
		if ((score == 'X' || score == 'O' || score == '.') && score < 126)
		{
			++score;
			place_number(datas, score, (score - 2));
		}
		else
			place_number(datas, score, (score - 1));
	}
	return (1);
}
