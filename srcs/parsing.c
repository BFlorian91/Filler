/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:17:04 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/19 14:39:53 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/filler.h"

int parsing_map(t_filler *datas)
{
	int 			i;
	unsigned int	x;
	unsigned int 	y;
	char	tmp[B_SIZE];

	i = 0;
	y = 0;
	ft_strcpy(tmp, ft_strstr(datas->buffer, "000"));
	/*if (!(tmp = ft_strdup(ft_strstr(datas->buffer, "000"))))*/
		/*return (-1);*/
	if (!(datas->map = (char **)malloc(sizeof(char *) * (datas->map_height + 1))))
		return (-1);
	datas->map[datas->map_height] = 0;
	while (y < datas->map_height)
	{
		x = 0;
		if (!(datas->map[y] = (char *)malloc(sizeof(char) * (datas->map_width + 1))))
				return (-1);
		ft_bzero(datas->map[y], datas->map_height);
		while (ft_isdigit(tmp[i]) || tmp[i] == ' ')
			++i;
		while (x < datas->map_width)
		{
			datas->map[y][x] = tmp[i];
			++x;
			++i;
		}
		datas->map[y][x] = '\0';
		++y;
	}
	
	print_board(datas->map);
	/*ft_strdel(&tmp);*/
	return (1);
}

int	parsing_pieces(t_filler *datas, char tmp[B_SIZE])
{
	int 			i;
	unsigned int	x;
	unsigned int	y;

	i = 0;
	y = 0;
	if (!(datas->piece = (char **)malloc(sizeof(char *) * (datas->piece_height + 1))))
		return (-1);
	datas->piece[datas->piece_height] = 0;
	while (y < datas->piece_height)
	{
		x = 0;
		if (!(datas->piece[y] = (char *)malloc(sizeof(char) * (datas->piece_width + 1))))
			return (-1);
		ft_bzero(datas->piece[y], datas->piece_height);
		while (tmp[i] == ':' || tmp[i] == ' ' || ft_isdigit(tmp[i]))
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
	print_board(datas->piece);
	return (1);
}