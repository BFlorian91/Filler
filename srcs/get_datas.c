/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:36:56 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/19 14:44:04 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int get_players(t_filler *datas)
{
	if (ft_strstr(datas->buffer, "$$$ exec p1 : [./flbeaumo.filler]"))
	{
		datas->player = 1;
		datas->letter_me = 'O';
		datas->letter_enemy = 'X';
	}
	else
	{
		datas->player = 2;
		datas->letter_me = 'X';
		datas->letter_enemy = '0';
	}
	return (1);
}


int	get_map(t_filler *datas)
{
	int 	i;
	char	tmp[B_SIZE];

	i = 0;
	NBR(i);
	ft_strcpy(tmp, ft_strstr(datas->buffer, "Plateau "));
	skip_spaces(tmp, &i);
	NBR(i);
	datas->map_height = get_number(tmp, &i);
	skip_spaces(tmp, &i);
	datas->map_width = get_number(tmp, &i);
	parsing_map(datas);
	return (1);
}

int	get_pieces(t_filler *datas)
{
	int		i;
	char	tmp[B_SIZE];

	i = 0;
	if (ft_strstr(datas->buffer, "Piece"))
		ft_strcpy(tmp, ft_strstr(datas->buffer, "Piece"));
	skip_spaces(tmp, &i);
	datas->piece_height = get_number(tmp, &i);
	skip_spaces(tmp, &i);
	datas->piece_width = get_number(tmp, &i);
	parsing_pieces(datas, tmp);
	return (1);
}
