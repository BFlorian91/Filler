/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:36:56 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/14 16:08:30 by flbeaumo         ###   ########.fr       */
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

static int parsing_map(t_filler *datas)
{
	int 	i;
	int		j;
	int		x;
	int 	y;
	char	tmp[4096];

	i = 0;
	j = 0;
	y = 0;
	ft_strcpy(tmp, ft_strstr(datas->buffer, "000"));
	if (!(datas->map = (char **)malloc(sizeof(char *) * (y + 1))))
		return (-1);
	while (y < datas->map_height)
	{
		x = 0;
		while (j < 5)
			++j;
		i += j;
		j = 0;
		if (!(datas->map[y] = (char *)malloc(sizeof(char) * (x + 1))))
				return (-1);
		ft_bzero(datas->map[y], datas->map_width);
		while (x < datas->map_width)
		{
			datas->map[y][x] = tmp[i];
			++x;
			++i;
		}
		datas->map[y][x] = '\0';
		++y;
	}
	datas->map[y] = 0;
	print_board(datas);
	return (1);
}

int	get_map(t_filler *datas)
{
	int 	i;
	char	tmp[4096];
	int		value;

	i = 0;
	value = 0;
	ft_strcpy(tmp, ft_strstr(datas->buffer, "Plateau "));
	while (!ft_isdigit(tmp[i]))
		++i;
	datas->map_width = get_number(tmp, &i);
	while (!ft_isdigit(tmp[i]))
		++i;
	datas->map_height = get_number(tmp, &i);
	parsing_map(datas);
	return (1);
}
