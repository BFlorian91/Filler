/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:20:51 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/07/31 16:04:51 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		heat_map(t_filler *datas)
{
	int		i;
	int		j;
	char	score;

	i = 1;
	score = 48;
	while (i + 1 < datas->map_height)
	{
		j = 1;
		while (j + 1 < datas->map_width)
		{
			if (datas->map[i][j] == datas->letter_enemy)			
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
		score < 126 ? ++score : 0;
	}
	print_board(datas->map);
	STR("\n");
	return (1);
}
