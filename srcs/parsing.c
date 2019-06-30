/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:17:04 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/30 11:14:32 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int parsing_map(t_filler *datas)
{
	int	i;

	i = 0;
	if (!(get_next_line(0, &datas->line)))
		return (-1);
	ft_strdel(&datas->line);
	if (!(datas->map = (char **)malloc(sizeof(char *) * (datas->map_height + 1))))
		return (-1);
	datas->map[datas->map_height] = 0;
	while (i < datas->map_height)
	{
		get_next_line(0, &datas->line);
		datas->map[i] = ft_strdup(datas->line + 4);
		ft_strdel(&datas->line);
		i++;
	}
	/* DEBUG */
	/*STR("THE MAP PARSE:\n");*/
	/*print_board(datas->map);*/
	/* END */
	return (1);
}

int	parsing_pieces(t_filler *datas)
{
	int	i;

	i = 0;
	if (!(datas->piece = (char **)malloc(sizeof(char *) * (datas->piece_height + 1))))
		return (-1);
	datas->piece[datas->piece_height] = 0;
	while (i < datas->piece_height)
	{
		if (!(get_next_line(0, &datas->line)))
			return (-1);
		datas->piece[i] = ft_strdup(datas->line);
		ft_strdel(&datas->line);
		++i;
	}
	/* DEBUG */
	/*STR("\n\nTHE PIECE PARSE: ");*/
	/*NBR(datas->piece_height);*/
	/*CHAR(' ');*/
	/*NBR(datas->piece_width);*/
	/*CHAR('\n');*/
	/*print_board(datas->piece);*/
	/* END */
	return (1);
}
