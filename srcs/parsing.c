/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:17:04 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/27 00:21:26 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/filler.h"

int parsing_map(t_filler *datas)
{
	int 		i;
	int			x;
	int			y;
	/*char	tmp[B_SIZE];*/

	i = 0;
	y = 0;
	STR(datas->line);
	get_next_line(0, &datas->line);
	if (!(datas->map = (char **)malloc(sizeof(char *) * (datas->map_height + 1))))
		return (-1);
	datas->map[datas->map_height] = 0;
	while (y < datas->map_height)
	{
		x = 0;
		if (!(datas->map[y] = (char *)malloc(sizeof(char) * (datas->map_width + 1))))
				return (-1);
		ft_bzero(datas->map[y], datas->map_height);
		get_next_line(0, &datas->line);
		while (ft_isdigit(datas->line[i]) || datas->line[i] == ' ')
			++i;
		while (x < datas->map_width)
		{
			datas->map[y][x] = datas->line[i];
			++x;
			++i;
		}
		datas->map[y][x] = '\0';
		++y;
	}
	/* DEBUG */
	/*STR("THE MAP PARSE:\n");*/
	/*print_board(datas->map);*/
	/* END */
	/*ft_strdel(&tmp);*/
	return (1);
}

int	parsing_pieces(t_filler *datas)
{
	int 			i;
	int	x;
	int	y;
	char			tmp[B_SIZE];

	i = 0;
	y = 0;
	if (ft_strstr(datas->buffer, "Piece"))
		ft_strcpy(tmp, ft_strstr(datas->buffer, "Piece"));
	if (!(datas->piece = (char **)malloc(sizeof(char *) * (datas->piece_height + 1))))
		return (-1);
	datas->piece[datas->piece_height] = 0;
	while (y < datas->piece_height)
	{
		x = 0;
		if (!(datas->piece[y] = (char *)malloc(sizeof(char) * (datas->piece_width + 1))))
			return (-1);
		ft_bzero(datas->piece[y], datas->piece_height);
		while (ft_isalpha(tmp[i]) || tmp[i] == ':' || ft_isdigit(tmp[i]) || tmp[i] == ' ')
			++i;
		while (x < datas->piece_width)
		{
			datas->piece[y][x] = tmp[i];
			++x;
			++i;
		}
		datas->piece[y][x] = '\0';
		++y;
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

int	get_current_piece(t_filler *datas)
{
	if (!(datas->pos = (t_pos *)malloc(sizeof(datas->piece_width))))
		return (-1);
	
	return (1);
}
