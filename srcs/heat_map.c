/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:20:51 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/07/31 13:29:14 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		heat_map(t_filler *datas)
{
	int	i;
	int j;
	int	score;

	i = 1;
	score = 0;
	while (datas->map[i + 1])
	{
		j = 1;
		while (datas->map[i][j + 1])
		{
			// do something...
			if (datas->piece[i][j] == '*' && datas->map[i + datas->y][j + datas->x] == datas->letter_enemy)			
			{
				datas->map[i - 1][j] = score;
				datas->map[i + 1][j] = score;
				datas->map[i][j - 1] = score;
				datas->map[i][j + 1] = score;
				++score;
			}
			++j;
		}
		++i;
	}
	/*print_board(datas->map);*/
	return (1);
}
