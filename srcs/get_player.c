/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:49:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/13 15:48:53 by flbeaumo         ###   ########.fr       */
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
	char	tmp[4096];
	int		value;

	i = 0;
	value = 0;
	ft_strcpy(tmp, ft_strstr(datas->buffer, "Plateau "));
	while (!ft_isdigit(tmp[i]))
		++i;
	datas->map_width = get_number(&tmp[i]);
	while (!ft_isdigit(tmp[i]))
		++i;
	datas->map_height = get_number(&tmp[i + 3]);  // pas BON ! i + 3 si 100?
	return (1);
}



	/*ft_putnbr_fd(datas->map_height, 2);*/
	/*ft_putstr_fd("CHARACTER\n", 2);*/
	/*ft_putchar_fd(tmp[i], 2);*/
	/*write(1, "\n", 2);*/
