/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:36:56 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/27 00:02:48 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int get_players(t_filler *datas)
{
	while (get_next_line(0, &datas->line))
	{
		if (ft_strstr(datas->line, "$$$ exec p1 : [./flbeaumo.filler]"))
		{
			datas->player = 1;
			datas->letter_me = 'O';
			datas->letter_enemy = 'X';
			break ;
		}
		else
		{
			datas->player = 2;
			datas->letter_me = 'X';
			datas->letter_enemy = 'O';
			break ;
		}
	}
	ft_strdel(&datas->line);
	return (1);
}


int	get_map(t_filler *datas)
{
	int 	i;
	int		j;
	/*char	tmp[B_SIZE];*/

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
		}
	}
	parsing_map(datas);
	return (1);
}

int	get_pieces(t_filler *datas)
{
	int		i;
	/*char	tmp[B_SIZE];*/

	i = 0;
	if (ft_strstr(datas->line, "Piece"))
	{
		/*ft_strcpy(tmp, ft_strstr(datas->buffer, "Piece"));*/
		while (!ft_isdigit(datas->line[i]))
			++i;
		datas->piece_height = get_number(datas->line, &i);
		while (!ft_isdigit(datas->line[i]))
			++i;
		datas->piece_width = get_number(datas->line, &i);
	}
	parsing_pieces(datas);
	return (1);
}
