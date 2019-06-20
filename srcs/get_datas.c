/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:36:56 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/20 10:58:38 by flbeaumo         ###   ########.fr       */
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
	ft_strcpy(tmp, ft_strstr(datas->buffer, "Plateau "));
	while (!ft_isdigit(tmp[i]))
		++i;
	datas->map_height = get_number(tmp, &i);
	while (!ft_isdigit(tmp[i]))
		++i;
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
	while (!ft_isdigit(tmp[i]))
		++i;
	datas->piece_height = get_number(tmp, &i);
	while (!ft_isdigit(tmp[i]))
		++i;
	datas->piece_width = get_number(tmp, &i);
	parsing_pieces(datas);
	return (1);
}
