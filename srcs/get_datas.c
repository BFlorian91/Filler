/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:36:56 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/29 15:10:48 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int get_players(t_filler *datas)
{
		if (!(get_next_line(0, &datas->line)))
			return (-1);
		if (ft_strstr(datas->line, "$$$ exec p1 : [./flbeaumo.filler]"))
		{
			datas->player = 1;
			datas->letter_me = 'O';
			datas->letter_enemy = 'X';
		}
		else
		{
			datas->player = 2;
			datas->letter_me = 'X';
			datas->letter_enemy = 'O';
		}
	ft_strdel(&datas->line);
	return (1);
}


int	get_map(t_filler *datas)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (get_next_line(0, &datas->line))
	{
		if (ft_strstr(datas->line, "Plateau "))
		{
			while (!ft_isdigit(datas->line[i]))
				++i;
			datas->map_height = get_number(datas->line, &i);
			while (!ft_isdigit(datas->line[i]))
				++i;
			datas->map_width = get_number(datas->line, &i);
			break ;
		}
	}
	ft_strdel(&datas->line);
	parsing_map(datas);
	return (1);
}

int	get_pieces(t_filler *datas)
{
	int	i;

	i = 0;
	while (get_next_line(0, &datas->line))
	{
		if (ft_strstr(datas->line, "Piece"))
		{
			while (!ft_isdigit(datas->line[i]))
				++i;
			datas->piece_height = get_number(datas->line, &i);
			while (!ft_isdigit(datas->line[i]))
				++i;
			datas->piece_width = get_number(datas->line, &i);
			break ;
		}
	}
	ft_strdel(&datas->line);
	parsing_pieces(datas);
	return (1);
}
