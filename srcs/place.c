/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:06:52 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/08/08 14:54:30 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*static void		skip_point(t_filler *datas)*/
/*{*/

	/*int	i;*/
	/*int	j;*/

	/*j = 0;*/
	/*i = 0;*/
	/*while (j < datas->piece_height && datas->piece[j][i] == '.')*/
	/*{*/
		/*j++;*/
		/*if (j == datas->piece_height)*/
		/*{*/
			/*j = 0;*/
			/*i++;*/
		/*}*/
	/*}*/
	/*datas->x_without_point = i;*/
	/*j = 0;*/
	/*while (i < datas->piece_width && datas->piece[j][i] == '.')*/
	/*{*/
		/*i++;*/
		/*if (i == datas->piece_width)*/
		/*{*/
			/*i = 0;*/
			/*j++;*/
		/*}*/
	/*}*/
	/*datas->y_without_point = j;*/

///////////////////////////////////////////////////////////////////////////////////////

	/*int i;*/
	/*int j;*/

	/*i = 0;*/
	/*while (datas->piece[i])*/
	/*{*/
		/*j = 0;*/
		/*while (datas->piece[i][j] != '*')*/
		/*{*/
			/*datas->x_without_point = j;*/
			/*++j;*/
		/*}*/
		/*++i;*/
	/*}*/
	/*i = 0;*/
	/*while (datas->piece[i])*/
	/*{*/
		/*j = 0;*/
		/*while (datas->piece[i][j] != '*')*/
			/*++j;*/
		/*if (j == datas->piece_width)*/
		/*{*/
			/*++i;*/
			/*datas->y_without_point = i;*/
		/*}*/
		/*else*/
			/*break ;*/
	/*}*/
	/*STR("IN THE FUNCTION\n");*/
	/*datas->y_without_point = i;*/
	/*NBR(datas->y_without_point);*/
	/*BACKN;*/
	/*NBR(datas->x_without_point);*/
	/*BACKN;*/
	/*BACKN;*/
	/*STR("IN THE PLACE\n");*/
/*}*/

static int		score_calculator(t_filler *datas)
{
	int i;
	int j;
	int	score;

	i = 0;
	score = 0;
	while (datas->piece[i])
	{
		j = 0;
		while (datas->piece[i][j])
		{
			if (datas->piece[i][j] == '*')
				score += datas->map[datas->y + i][datas->x + j];
			++j;
		}
		++i;
	}
	return (score);
}

static int		can_place(t_filler *datas)
{
	int 	i;
	int 	j;
	int		my_player_char;	

	i = 0;
	my_player_char = 0;
	while (i + datas->y < datas->map_height && i < datas->piece_height)
	{
		j = 0;
		while (j + datas->x < datas->map_width && j < datas->piece_width)
		{
			if (datas->piece[i][j] == '*' && datas->map[i + datas->y]
					[j + datas->x] == datas->letter_me)
				++my_player_char;
			if (datas->piece[i][j] == '*' && datas->map[i + datas->y]
					[j + datas->x] == datas->letter_enemy)
				return (0);
			++j;
		}
		++i;
	}
	return (my_player_char == 1 ? 1 : 0);
}

int		place(t_filler *datas)
{
	int score;

	score = 0;
	/*skip_point(datas);*/
	/*datas->y = -(datas->y_without_point);*/
	datas->y = 0;
	heat_map(datas);
	/*lifting_pieces(datas);*/
	while (datas->y + datas->piece_height <= datas->map_height)
	{
		/*datas->x = -(datas->x_without_point);*/
		datas->y == 0 ? (datas->x = 1) : (datas->x = 0);
		while (datas->x + datas->piece_width <= datas->map_width)
		{
			if (can_place(datas))
			{
				if ((score = score_calculator(datas)) < datas->optimus_score 
						|| datas->optimus_score == 0)
				{
					datas->optimus_score = score;
					datas->optimus_x = datas->x;
					datas->optimus_y = datas->y;
				}
			}
			++(datas->x);
		}
		++(datas->y);
	}
	if (datas->optimus_score == 0)
		ft_printf("0 0\n");
	else
		ft_printf("%s %s\n", ft_itoa(datas->optimus_y),
				ft_itoa(datas->optimus_x));
	return (0);
}
